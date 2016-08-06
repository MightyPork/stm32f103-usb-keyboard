/**
  ******************************************************************************
  * @file    usbd_core.h
  * @author  MCD Application Team
  * @version V2.4.2
  * @date    11-December-2015
  * @brief   Header file for usbd_core.c file
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT 2015 STMicroelectronics</center></h2>
  *
  * Licensed under MCD-ST Liberty SW License Agreement V2, (the "License");
  * You may not use this file except in compliance with the License.
  * You may obtain a copy of the License at:
  *
  *        http://www.st.com/software_license_agreement_liberty_v2
  *
  * Unless required by applicable law or agreed to in writing, software 
  * distributed under the License is distributed on an "AS IS" BASIS, 
  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  * See the License for the specific language governing permissions and
  * limitations under the License.
  *
  ******************************************************************************
  */ 

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __USBD_CORE_H
#define __USBD_CORE_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "usbd_conf.h"
#include "usbd_def.h"
#include "usbd_ioreq.h"
#include "usbd_ctlreq.h"

/** @addtogroup STM32_USB_DEVICE_LIBRARY
  * @{
  */
  
/** @defgroup USBD_CORE
  * @brief This file is the Header file for usbd_core.c file
  * @{
  */ 


/** @defgroup USBD_CORE_Exported_Defines
  * @{
  */ 

/**
  * @}
  */ 


/** @defgroup USBD_CORE_Exported_TypesDefinitions
  * @{
  */
 

/**
  * @}
  */ 



/** @defgroup USBD_CORE_Exported_Macros
  * @{
  */ 

/**
  * @}
  */ 

/** @defgroup USBD_CORE_Exported_Variables
  * @{
  */ 
#define USBD_SOF          USBD_LL_SOF
/**
  * @}
  */ 

/** @defgroup USBD_CORE_Exported_FunctionsPrototype
  * @{
  */ 


/*- injected dox -*/
/**
* @brief  USBD_Init
*         Initializes the device stack and load the class driver
* @param  pdev: device instance
* @param  pdesc: Descriptor structure address
* @param  id: Low level core index
* @retval None
*/
USBD_StatusTypeDef USBD_Init(USBD_HandleTypeDef *pdev, USBD_DescriptorsTypeDef *pdesc, uint8_t id);


/*- injected dox -*/
/**
* @brief  USBD_DeInit 
*         Re-Initialize th device library
* @param  pdev: device instance
* @retval status: status
*/
USBD_StatusTypeDef USBD_DeInit(USBD_HandleTypeDef *pdev);


/*- injected dox -*/
/**
  * @brief  USBD_Start 
  *         Start the USB Device Core.
  * @param  pdev: Device Handle
  * @retval USBD Status
  */
USBD_StatusTypeDef USBD_Start  (USBD_HandleTypeDef *pdev);


/*- injected dox -*/
/**
  * @brief  USBD_Stop 
  *         Stop the USB Device Core.
  * @param  pdev: Device Handle
  * @retval USBD Status
  */
USBD_StatusTypeDef USBD_Stop   (USBD_HandleTypeDef *pdev);


/*- injected dox -*/
/**
  * @brief  USBD_RegisterClass 
  *         Link class driver to Device Core.
  * @param  pDevice : Device Handle
  * @param  pclass: Class handle
  * @retval USBD Status
  */
USBD_StatusTypeDef USBD_RegisterClass(USBD_HandleTypeDef *pdev, USBD_ClassTypeDef *pclass);



/*- injected dox -*/
/**
* @brief  USBD_RunTestMode 
*         Launch test mode process
* @param  pdev: device instance
* @retval status
*/
USBD_StatusTypeDef USBD_RunTestMode (USBD_HandleTypeDef  *pdev); 


/*- injected dox -*/
/**
* @brief  USBD_SetClassConfig 
*        Configure device and start the interface
* @param  pdev: device instance
* @param  cfgidx: configuration index
* @retval status
*/
USBD_StatusTypeDef USBD_SetClassConfig(USBD_HandleTypeDef  *pdev, uint8_t cfgidx);


/*- injected dox -*/
/**
* @brief  USBD_ClrClassConfig 
*         Clear current configuration
* @param  pdev: device instance
* @param  cfgidx: configuration index
* @retval status: USBD_StatusTypeDef
*/
USBD_StatusTypeDef USBD_ClrClassConfig(USBD_HandleTypeDef  *pdev, uint8_t cfgidx);



/*- injected dox -*/
/**
* @brief  USBD_SetupStage 
*         Handle the setup stage
* @param  pdev: device instance
* @retval status
*/
USBD_StatusTypeDef USBD_LL_SetupStage(USBD_HandleTypeDef *pdev, uint8_t *psetup);


/*- injected dox -*/
/**
* @brief  USBD_DataOutStage 
*         Handle data OUT stage
* @param  pdev: device instance
* @param  epnum: endpoint index
* @retval status
*/
USBD_StatusTypeDef USBD_LL_DataOutStage(USBD_HandleTypeDef *pdev , uint8_t epnum, uint8_t *pdata);


/*- injected dox -*/
/**
* @brief  USBD_DataInStage 
*         Handle data in stage
* @param  pdev: device instance
* @param  epnum: endpoint index
* @retval status
*/
USBD_StatusTypeDef USBD_LL_DataInStage(USBD_HandleTypeDef *pdev , uint8_t epnum, uint8_t *pdata);



/*- injected dox -*/
/**
* @brief  USBD_LL_Reset 
*         Handle Reset event
* @param  pdev: device instance
* @retval status
*/
USBD_StatusTypeDef USBD_LL_Reset(USBD_HandleTypeDef  *pdev);


/*- injected dox -*/
/**
* @brief  USBD_LL_Reset 
*         Handle Reset event
* @param  pdev: device instance
* @retval status
*/
USBD_StatusTypeDef USBD_LL_SetSpeed(USBD_HandleTypeDef  *pdev, USBD_SpeedTypeDef speed);


/*- injected dox -*/
/**
* @brief  USBD_Suspend 
*         Handle Suspend event
* @param  pdev: device instance
* @retval status
*/
USBD_StatusTypeDef USBD_LL_Suspend(USBD_HandleTypeDef  *pdev);


/*- injected dox -*/
/**
* @brief  USBD_Resume 
*         Handle Resume event
* @param  pdev: device instance
* @retval status
*/
USBD_StatusTypeDef USBD_LL_Resume(USBD_HandleTypeDef  *pdev);



/*- injected dox -*/
/**
* @brief  USBD_SOF 
*         Handle SOF event
* @param  pdev: device instance
* @retval status
*/
USBD_StatusTypeDef USBD_LL_SOF(USBD_HandleTypeDef  *pdev);


/*- injected dox -*/
/**
* @brief  USBD_IsoINIncomplete 
*         Handle iso in incomplete event
* @param  pdev: device instance
* @retval status
*/
USBD_StatusTypeDef USBD_LL_IsoINIncomplete(USBD_HandleTypeDef  *pdev, uint8_t epnum);


/*- injected dox -*/
/**
* @brief  USBD_IsoOUTIncomplete 
*         Handle iso out incomplete event
* @param  pdev: device instance
* @retval status
*/
USBD_StatusTypeDef USBD_LL_IsoOUTIncomplete(USBD_HandleTypeDef  *pdev, uint8_t epnum);



/*- injected dox -*/
/**
* @brief  USBD_DevConnected 
*         Handle device connection event
* @param  pdev: device instance
* @retval status
*/
USBD_StatusTypeDef USBD_LL_DevConnected(USBD_HandleTypeDef  *pdev);


/*- injected dox -*/
/**
* @brief  USBD_DevDisconnected 
*         Handle device disconnection event
* @param  pdev: device instance
* @retval status
*/
USBD_StatusTypeDef USBD_LL_DevDisconnected(USBD_HandleTypeDef  *pdev);

/* USBD Low Level Driver */


/*- injected dox -*/
/**
  * @brief  Initializes the Low Level portion of the Device driver.
  * @param  pdev: Device handle
  * @retval USBD Status
  */
USBD_StatusTypeDef USBD_LL_Init (USBD_HandleTypeDef *pdev);


/*- injected dox -*/
/**
  * @brief  De-Initializes the Low Level portion of the Device driver.
  * @param  pdev: Device handle
  * @retval USBD Status
  */
USBD_StatusTypeDef USBD_LL_DeInit (USBD_HandleTypeDef *pdev);


/*- injected dox -*/
/**
  * @brief  Starts the Low Level portion of the Device driver. 
  * @param  pdev: Device handle
  * @retval USBD Status
  */
USBD_StatusTypeDef USBD_LL_Start(USBD_HandleTypeDef *pdev);


/*- injected dox -*/
/**
  * @brief  Stops the Low Level portion of the Device driver.
  * @param  pdev: Device handle
  * @retval USBD Status
  */
USBD_StatusTypeDef USBD_LL_Stop (USBD_HandleTypeDef *pdev);


/*- injected dox -*/
/**
  * @brief  Opens an endpoint of the Low Level Driver.
  * @param  pdev: Device handle
  * @param  ep_addr: Endpoint Number
  * @param  ep_type: Endpoint Type
  * @param  ep_mps: Endpoint Max Packet Size
  * @retval USBD Status
  */
USBD_StatusTypeDef USBD_LL_OpenEP  (USBD_HandleTypeDef *pdev, 
                                      uint8_t  ep_addr,                                      
                                      uint8_t  ep_type,
                                      uint16_t ep_mps);



/*- injected dox -*/
/**
  * @brief  Closes an endpoint of the Low Level Driver.
  * @param  pdev: Device handle
  * @param  ep_addr: Endpoint Number
  * @retval USBD Status
  */
USBD_StatusTypeDef USBD_LL_CloseEP (USBD_HandleTypeDef *pdev, uint8_t ep_addr);   


/*- injected dox -*/
/**
  * @brief  Flushes an endpoint of the Low Level Driver.
  * @param  pdev: Device handle
  * @param  ep_addr: Endpoint Number
  * @retval USBD Status
  */
USBD_StatusTypeDef USBD_LL_FlushEP (USBD_HandleTypeDef *pdev, uint8_t ep_addr);   


/*- injected dox -*/
/**
  * @brief  Sets a Stall condition on an endpoint of the Low Level Driver.
  * @param  pdev: Device handle
  * @param  ep_addr: Endpoint Number
  * @retval USBD Status
  */
USBD_StatusTypeDef USBD_LL_StallEP (USBD_HandleTypeDef *pdev, uint8_t ep_addr);   


/*- injected dox -*/
/**
  * @brief  Clears a Stall condition on an endpoint of the Low Level Driver.
  * @param  pdev: Device handle
  * @param  ep_addr: Endpoint Number
  * @retval USBD Status
  */
USBD_StatusTypeDef USBD_LL_ClearStallEP (USBD_HandleTypeDef *pdev, uint8_t ep_addr);   


/*- injected dox -*/
/**
  * @brief  Returns Stall condition.
  * @param  pdev: Device handle
  * @param  ep_addr: Endpoint Number
  * @retval Stall (1: Yes, 0: No)
  */
uint8_t USBD_LL_IsStallEP (USBD_HandleTypeDef *pdev, uint8_t ep_addr);   


/*- injected dox -*/
/**
  * @brief  Assigns a USB address to the device.
  * @param  pdev: Device handle
  * @param  ep_addr: Endpoint Number
  * @retval USBD Status
  */
USBD_StatusTypeDef USBD_LL_SetUSBAddress (USBD_HandleTypeDef *pdev, uint8_t dev_addr);   


/*- injected dox -*/
/**
  * @brief  Transmits data over an endpoint.
  * @param  pdev: Device handle
  * @param  ep_addr: Endpoint Number
  * @param  pbuf: Pointer to data to be sent
  * @param  size: Data size    
  * @retval USBD Status
  */
USBD_StatusTypeDef USBD_LL_Transmit (USBD_HandleTypeDef *pdev, 
                                      uint8_t  ep_addr,                                      
                                      uint8_t  *pbuf,
                                      uint16_t  size);



/*- injected dox -*/
/**
  * @brief  Prepares an endpoint for reception.
  * @param  pdev: Device handle
  * @param  ep_addr: Endpoint Number
  * @param  pbuf: Pointer to data to be received
  * @param  size: Data size
  * @retval USBD Status
  */
USBD_StatusTypeDef USBD_LL_PrepareReceive(USBD_HandleTypeDef *pdev, 
                                           uint8_t  ep_addr,                                      
                                           uint8_t  *pbuf,
                                           uint16_t  size);



/*- injected dox -*/
/**
  * @brief  Returns the last transfered packet size.
  * @param  pdev: Device handle
  * @param  ep_addr: Endpoint Number
  * @retval Recived Data Size
  */
uint32_t USBD_LL_GetRxDataSize  (USBD_HandleTypeDef *pdev, uint8_t  ep_addr);  


/*- injected dox -*/
/**
  * @brief  Delays routine for the USB Device Library.
  * @param  Delay: Delay in ms
  * @retval None
  */
void USBD_LL_Delay (uint32_t Delay);

/**
  * @}
  */ 

#ifdef __cplusplus
}
#endif

#endif /* __USBD_CORE_H */

/**
  * @}
  */ 

/**
* @}
*/ 

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/



