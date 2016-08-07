//
// Created by MightyPork on 7.8.16.
//

#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include "keyboard.h"

static uint8_t modifiers = 0x00;

static uint8_t keys[KYBD_SLOTS] = {};

static uint8_t free_slot = 0;

static bool err_ovf = false;

/** Clear keys and mods */
void kybd_clear() {
	memset(keys, 0x00, KYBD_SLOTS);
	modifiers = 0x00;
	free_slot = 0;
	err_ovf = false;
}

/** Key down */
bool kybd_press(uint8_t key) {
	kybd_key(key, true);
}

/** Key up */
bool kybd_release(uint8_t key) {
	kybd_key(key, false);
}

/** Modifier press or release */
void kybd_mod(uint8_t mod, bool press) {
	if (press) {
		modifiers |= mod;
	} else {
		modifiers &= ~mod;
	}
}

/** Key press or release */
bool kybd_key(uint8_t key, bool press) {
	if (key >= KEY_LEFTCTRL && key <= KEY_RIGHTMETA) {
		// Modifier key

		// conveniently, the lower byte indicates the modifier position
		uint8_t bitshift = (uint8_t) (key & 0x0F);
		// obtain the modifier mask
		uint8_t mod = (uint8_t) (1 << bitshift);
		// apply modifier
		kybd_mod(mod, press);

		goto suc;
	}

	// Regular key
	if (press) {
		for (int i = 0; i < KYBD_SLOTS; i++) {
			if (keys[i] == key) {
				// key is already pressed
				goto suc;
			}
		}

		if (free_slot < KYBD_SLOTS) {
			// press the key
			keys[free_slot++] = key;
			goto suc;
		}

		err_ovf = true; // set overflow flag
	}
	else {
		// release
		bool found = false;
		for (int i = 0; i < KYBD_SLOTS; i++) {
			if (found) {
				keys[i - 1] = keys[i];
				if (i == KYBD_SLOTS - 1) {
					keys[i] = 0x00;
				}
			}
			else {
				if (keys[i] == key) {
					found = true;
				}
			}
		}
		if (found) {
			err_ovf = false; // clear overflow flag
			free_slot--;
			goto suc;
		}
	}

	return false;
suc:
	return true;
}

/** Get HID report */
void kybd_get_bytes(uint8_t *arr) {
	arr[0] = modifiers;
	arr[1] = 0x00;

	if (err_ovf) {
		// all slots ERR_OVF
		memset(arr + 2, KEY_ERR_OVF, KYBD_SLOTS);
	} else {
		// show keys
		memcpy(arr + 2, keys, KYBD_SLOTS);
	}
}
