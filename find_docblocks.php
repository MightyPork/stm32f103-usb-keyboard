#!/bin/env php
<?php

if ($argc != 3) {
	echo "[E] Need 2 arguments: (.c file), (.h file)\n";
	exit;
}

$cfile = $argv[1];
$hfile = $argv[2];

if (!file_exists($cfile)) {
	echo "[E] File not found.\n";
	exit;
}

$ctxt = file_get_contents($cfile);
$htxt = file_get_contents($hfile);

preg_match_all('/(\/\*\*(?:.(?!\/\*\*))*?\*\/)\s+([a-z_+0-9]+)\s+([a-z_+0-9]+)\s*(?=\()/si', $ctxt, $matches);
$dox = $matches[1];
$types = $matches[2];
$names = $matches[3];


$x = $htxt;
for ($i = 0; $i < count($dox); $i++) {
	$search = '/' . preg_quote($types[$i]) . '\s+' . preg_quote($names[$i]) . '/';
	$replacement = "\n\n/*- injected dox -*/\n" . $dox[$i] . "\n" . $types[$i] . ' ' . $names[$i];

	$x = preg_replace($search, $replacement, $x);
}

echo $x;
