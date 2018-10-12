
#include "Console.h"

#ifdef __GNUC__
  /* With GCC/RAISONANCE, small printf (option LD Linker->Libraries->Small printf
     set to 'Yes') calls __io_putchar() */
  #define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
  #define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#endif /* __GNUC__ */

/*******************************************************************************
* Function Name  : main
* Description    : Main program
*******************************************************************************/
uint8_t color[11][3];
uint8_t Recv_data[5];

int main(void)
{
	  u8 cnt;
    u16 buff;
    Power_ON();	
	  Init();
		USART1_Config();
//   	RX_Init();
		for(cnt=0;cnt<60;cnt++)  TxBuf[cnt]=cnt+1;			
	  while(1)
		{
//			 if(RxBuf[0]!=0)
//				{					  
//					  writeCom1(RxBuf);
//					  GPIOC->ODR^=0X2000;						  
//					  for(cnt=0;cnt<60;cnt++) RxBuf[cnt]=0; 
//						for(cnt=0;cnt<5;cnt++)  Status[cnt]=GetRSSI(Status[cnt]);	
//						writeCom1(Status);												
//				}
//			    writeCom1(TxBuf);
//					Delay_ms(500);
//			    GPIOC->ODR^=0X2000;

				
				//IRSend(0X0F,IR_data,4);
				//Delay_ms(300);
		 
//			 GPIOC->ODR^=0X2000;
			IRSend(0x44,TxBuf,60);
			//GPIOB->ODR^=0X0020;
			//GPIO_ResetBits(GPIOC , GPIO_Pin_13);
			//GPIO_ResetBits(GPIOB , GPIO_Pin_3);
			//GPIO_ResetBits(GPIOB , GPIO_Pin_5);
			//Delay_ms(100);
			//GPIO_SetBits(GPIOC , GPIO_Pin_13);
			//GPIO_ResetBits(GPIOB , GPIO_Pin_3);
			//GPIO_SetBits(GPIOB , GPIO_Pin_5);


			   // GPIOC->BSRR=0X2000;
				  Delay_ms(100);	
		}
		NVIC_SystemReset();
}



/*******************************************************************************
* Function Name  : IWDG_Configuration
* Description    : 
* Input          : None
* Output         : None
* Return         : None
* Attention		 : None
*******************************************************************************/
void IWDG_Configuration(void)
{
  IWDG_WriteAccessCmd(IWDG_WriteAccess_Enable); 
  IWDG_SetPrescaler(IWDG_Prescaler_256);         
  IWDG_SetReload(3905);			//25s				 
  IWDG_ReloadCounter();								
  IWDG_Enable(); 									
}



#ifdef  USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *   where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{ 
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif



/*********************************************************************************************************
      END FILE
*********************************************************************************************************/
