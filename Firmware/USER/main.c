/*	brief:	This function can control a step motor to increase its speed from zero
						A step motor drive is needed for it work. 
*/
#include "STM32F407VET_Config.h"
#include "stm32f4xx.h"
#include "stm32f4xx_gpio.h"
#include "sys.h"
#include "delay.h"
						
#include "usbd_cdc_core.h"
#include "usbd_usr.h"
#include "usb_conf.h"
#include "usbd_desc.h"
#include "usbd_cdc_vcp.h"

#ifdef USB_OTG_HS_INTERNAL_DMA_ENABLED
  #if defined ( __ICCARM__ ) /*!< IAR Compiler */
    #pragma data_alignment=4   
  #endif
#endif /* USB_OTG_HS_INTERNAL_DMA_ENABLED */
   
__ALIGN_BEGIN USB_OTG_CORE_HANDLE    USB_OTG_dev __ALIGN_END ;

/*Variable to transfer informatin---------------------------------------------*/
extern u8 RX_Buffer[2048];
extern u32 RX_Length;
extern CDC_IF_Prop_TypeDef VCP_fops;

//extern u8 Test_Buffer[2048];
//extern u32 Test_Length;

/**
  * @}
  */ 


/** @defgroup APP_VCP_Private_FunctionPrototypes
  * @{
  */ 
/**
  * @}
  */ 


/** @defgroup APP_VCP_Private_Functions
  * @{
  */ 

/**
  * @brief  Program entry point
  * @param  None
  * @retval None
  */
int main(void)
{
uint8_t* Test_Buffer;
u32 Test_Length = 8;
	Test_Buffer = "abc34567";
  __IO uint32_t i = 0;  

  /*!< At this stage the microcontroller clock setting is already configured, 
  this is done through SystemInit() function which is called from startup
  file (startup_stm32fxxx_xx.s) before to branch to application main.
  To reconfigure the default setting of SystemInit() function, refer to
  system_stm32fxxx.c file
  */  
 
  USBD_Init(&USB_OTG_dev,
#ifdef USE_USB_OTG_HS 
            USB_OTG_HS_CORE_ID,
#else            
            USB_OTG_FS_CORE_ID,
#endif  
            &USR_desc, 
            &USBD_CDC_cb, 
            &USR_cb); //not useful, just for led. 
  
  /* Main loop */
  while (1)
  {
    if (i++ == 0x100000)
    {
		/*	if(RX_Length !=0 )
			{
				VCP_fops.pIf_DataTx(RX_Buffer, RX_Length);
				RX_Length = 0;
			} */
			VCP_fops.pIf_DataTx(Test_Buffer, Test_Length);
      i = 0;
		}
	}
} 
