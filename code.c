#include "easyDSP-Expansion_Board.h"
#include "math.h"

#define SAMPLING_FREQ 12000
#define PI 3.14159265358979
#define loop_time 12000/2
unsigned short f=0,sample=0;
unsigned short digital=15,old_digital=15;
short DTMF_count=0,DTMF_flag=0;

long count=0;
int state = 1;



int main(void)
{
  Board_Init(); //Initial easyDSP-Expansion_Board
  Setup_Audio_Init(FS_12000_HZ,ADC_GAIN_0DB,DAC_ATTEN_0DB,LINE_INPUT);

  while(1)
  {

      digital = Read_keypad();
      if (Read_SW(1)== 1 ){

      switch(digital)
           {
           case 15: //1
               if (state == 1){
                   f = 262 * 2;
               }
               else if(state == 2){
                   f = 262 * 4;
               }
               else if(state == 0){
                   f = 262 ;
               }
               Control_LED_OFF(1);
               Control_LED_OFF(2);
               Control_LED_OFF(3);
               Control_LED_ON(1);
            break;
           case 14: //2
               if (state == 1){
                 f = 294*2;
               }
               else if(state == 2){
                 f = 294 * 4;
               }
               else if(state == 0){
                   f = 294 ;
               }
               Control_LED_OFF(1);
               Control_LED_OFF(2);
               Control_LED_OFF(3);
               Control_LED_ON(2);


            break;
           case 13: // 3
               if (state == 1){
                 f = 330*2;
               }
               else if(state == 2){
                 f = 330 * 4;
               }
               else if(state == 0){
                   f = 330 ;
                 }
               Control_LED_OFF(1);
               Control_LED_OFF(2);
               Control_LED_OFF(3);
               Control_LED_ON(1);
               Control_LED_ON(2);

            break;
           case 11: // 4
               if (state == 1){
                 f = 349 *2;
               }
               else if(state == 2){
                 f = 349 * 4;
               }
               else if(state == 0){
                 f = 349 ;
               }
               Control_LED_OFF(1);
               Control_LED_OFF(2);
               Control_LED_OFF(3);
               Control_LED_ON(3);

            break;
           case 3: // 5
               if (state == 1){
                 f = 392*2;
               }
               else if(state == 2){
                 f = 392 * 4;
               }
               else if(state == 0){
                   f = 392 ;
               }
               Control_LED_OFF(1);
               Control_LED_OFF(2);
               Control_LED_OFF(3);
               Control_LED_ON(1);
               Control_LED_ON(3);
               break;
           case 6: // 6
               if (state == 1){
                 f = 440*2;
               }
               else if(state == 2){
                 f = 440 * 4;
               }
               else if(state == 0){
                   f = 440;
                 }
               Control_LED_OFF(1);
               Control_LED_OFF(2);
               Control_LED_OFF(3);
               Control_LED_ON(2);
               Control_LED_ON(3);

            break;
           case 10: // D
               if (state == 1){
                 f = 494*2;
               }
               else if(state == 2){
                 f = 494 * 4;
               }
               else if(state == 0){
                   f = 494;
                 }

               Control_LED_OFF(1);
               Control_LED_OFF(2);
               Control_LED_OFF(3);
               Control_LED_ON(1);
               Control_LED_ON(2);
               Control_LED_ON(3);
            break;
           case 2: //C
               if (state == 1){
                 f = 524*2;
               }
               else if(state == 2){
                 f = 524 * 4;
               }
               else if(state == 0){
                   f = 524 ;
                 }
            break;
           case 5: //B
               if (state == 1){
                 f = 588*2;
               }
               else if(state == 2){
                 f = 588 *4;
               }
               else if(state == 0){
                   f = 588 ;
                 }
            break;
           case 0:
               f=0;
          break;



          }
      }
      else {
                switch(digital)
                     {
                     case 15:
                         if (state == 1){
                             LCD_PUT_CMD(LCD_FIRST_LINE);
                             LCD_PUT_CHAR('O');
                             LCD_PUT_CHAR('R');
                             LCD_PUT_CHAR('I');
                             LCD_PUT_CHAR('G');
                             LCD_PUT_CHAR('I');
                             LCD_PUT_CHAR('N');
                             LCD_PUT_CMD(LCD_SECOND_LINE);
                             LCD_PUT_CHAR('D');
                             LCD_PUT_CHAR('O');

                         US_Delay(400000);
                         }
                         else if(state == 2){
                             LCD_PUT_CMD(LCD_FIRST_LINE);
                             LCD_PUT_CHAR('H');
                             LCD_PUT_CHAR('I');
                             LCD_PUT_CHAR('G');
                             LCD_PUT_CHAR('H');
                             LCD_PUT_CHAR('E');
                             LCD_PUT_CHAR('R');
                             LCD_PUT_CMD(LCD_SECOND_LINE);
                             LCD_PUT_CHAR('D');
                             LCD_PUT_CHAR('O');
                             US_Delay(400000);
                         }
                         else if(state == 0){
                             LCD_PUT_CMD(LCD_FIRST_LINE);
                             LCD_PUT_CHAR('L');
                             LCD_PUT_CHAR('O');
                             LCD_PUT_CHAR('W');
                             LCD_PUT_CHAR('E');
                             LCD_PUT_CHAR('R');
                             LCD_PUT_CHAR(' ');
                             LCD_PUT_CMD(LCD_SECOND_LINE);
                             LCD_PUT_CHAR('D');
                             LCD_PUT_CHAR('O');
                             US_Delay(400000);

                         }
                      break;
                     case 14:
                         if (state == 1){
                             LCD_PUT_CMD(LCD_FIRST_LINE);
                             LCD_PUT_CHAR('O');
                             LCD_PUT_CHAR('R');
                             LCD_PUT_CHAR('I');
                             LCD_PUT_CHAR('G');
                             LCD_PUT_CHAR('I');
                             LCD_PUT_CHAR('N');
                             LCD_PUT_CMD(LCD_SECOND_LINE);
                             LCD_PUT_CHAR('R');
                             LCD_PUT_CHAR('E');

                         US_Delay(400000);
                         }
                         else if(state == 2){
                             LCD_PUT_CMD(LCD_FIRST_LINE);
                             LCD_PUT_CHAR('H');
                             LCD_PUT_CHAR('I');
                             LCD_PUT_CHAR('G');
                             LCD_PUT_CHAR('H');
                             LCD_PUT_CHAR('E');
                             LCD_PUT_CHAR('R');
                             LCD_PUT_CMD(LCD_SECOND_LINE);
                             LCD_PUT_CHAR('R');
                             LCD_PUT_CHAR('E');
                             US_Delay(400000);
                         }
                         else if(state == 0){
                             LCD_PUT_CMD(LCD_FIRST_LINE);
                             LCD_PUT_CHAR('L');
                             LCD_PUT_CHAR('O');
                             LCD_PUT_CHAR('W');
                             LCD_PUT_CHAR('E');
                             LCD_PUT_CHAR('R');
                             LCD_PUT_CHAR(' ');
                             LCD_PUT_CMD(LCD_SECOND_LINE);
                             LCD_PUT_CHAR('R');
                             LCD_PUT_CHAR('E');
                             US_Delay(400000);

                         }
                      break;
                     case 13:
                         if (state == 1){
                             LCD_PUT_CMD(LCD_FIRST_LINE);
                             LCD_PUT_CHAR('O');
                             LCD_PUT_CHAR('R');
                             LCD_PUT_CHAR('I');
                             LCD_PUT_CHAR('G');
                             LCD_PUT_CHAR('I');
                             LCD_PUT_CHAR('N');
                             LCD_PUT_CMD(LCD_SECOND_LINE);
                             LCD_PUT_CHAR('M');
                             LCD_PUT_CHAR('I');

                         US_Delay(400000);
                         }
                         else if(state == 2){
                             LCD_PUT_CMD(LCD_FIRST_LINE);
                             LCD_PUT_CHAR('H');
                             LCD_PUT_CHAR('I');
                             LCD_PUT_CHAR('G');
                             LCD_PUT_CHAR('H');
                             LCD_PUT_CHAR('E');
                             LCD_PUT_CHAR('R');
                             LCD_PUT_CMD(LCD_SECOND_LINE);
                             LCD_PUT_CHAR('M');
                             LCD_PUT_CHAR('I');
                             US_Delay(400000);
                         }
                         else if(state == 0){
                             LCD_PUT_CMD(LCD_FIRST_LINE);
                             LCD_PUT_CHAR('L');
                             LCD_PUT_CHAR('O');
                             LCD_PUT_CHAR('W');
                             LCD_PUT_CHAR('E');
                             LCD_PUT_CHAR('R');
                             LCD_PUT_CHAR(' ');
                             LCD_PUT_CMD(LCD_SECOND_LINE);
                             LCD_PUT_CHAR('M');
                             LCD_PUT_CHAR('I');
                             US_Delay(400000);

                         }

                      break;
                     case 11: // #
                         if (state == 1){
                             LCD_PUT_CMD(LCD_FIRST_LINE);
                             LCD_PUT_CHAR('O');
                             LCD_PUT_CHAR('R');
                             LCD_PUT_CHAR('I');
                             LCD_PUT_CHAR('G');
                             LCD_PUT_CHAR('I');
                             LCD_PUT_CHAR('N');
                             LCD_PUT_CMD(LCD_SECOND_LINE);
                             LCD_PUT_CHAR('F');
                             LCD_PUT_CHAR('A');
                             US_Delay(400000);
                         }
                         else if(state == 2){
                             LCD_PUT_CMD(LCD_FIRST_LINE);
                             LCD_PUT_CHAR('H');
                             LCD_PUT_CHAR('I');
                             LCD_PUT_CHAR('G');
                             LCD_PUT_CHAR('H');
                             LCD_PUT_CHAR('E');
                             LCD_PUT_CHAR('R');

                             LCD_PUT_CMD(LCD_SECOND_LINE);
                             LCD_PUT_CHAR('F');
                             LCD_PUT_CHAR('A');
                             US_Delay(400000);

                         }
                         else if(state == 0){
                             LCD_PUT_CMD(LCD_FIRST_LINE);
                             LCD_PUT_CHAR('L');
                             LCD_PUT_CHAR('O');
                             LCD_PUT_CHAR('W');
                             LCD_PUT_CHAR('E');
                             LCD_PUT_CHAR('R');
                             LCD_PUT_CHAR(' ');
                             LCD_PUT_CMD(LCD_SECOND_LINE);
                             LCD_PUT_CHAR('F');
                             LCD_PUT_CHAR('A');
                             US_Delay(400000);
                         }

                      break;
                     case 3: // 9
                         if (state == 1){
                             LCD_PUT_CMD(LCD_FIRST_LINE);
                             LCD_PUT_CHAR('O');
                             LCD_PUT_CHAR('R');
                             LCD_PUT_CHAR('I');
                             LCD_PUT_CHAR('G');
                             LCD_PUT_CHAR('I');
                             LCD_PUT_CHAR('N');
                             LCD_PUT_CMD(LCD_SECOND_LINE);
                             LCD_PUT_CHAR('S');
                             LCD_PUT_CHAR('O');
                             US_Delay(400000);
                         }
                         else if(state == 2){
                             LCD_PUT_CMD(LCD_FIRST_LINE);
                             LCD_PUT_CHAR('H');
                             LCD_PUT_CHAR('I');
                             LCD_PUT_CHAR('G');
                             LCD_PUT_CHAR('H');
                             LCD_PUT_CHAR('E');
                             LCD_PUT_CHAR('R');
                             LCD_PUT_CMD(LCD_SECOND_LINE);
                             LCD_PUT_CHAR('S');
                             LCD_PUT_CHAR('O');
                             US_Delay(400000);
                         }
                         else if(state == 0){
                             LCD_PUT_CMD(LCD_FIRST_LINE);
                             LCD_PUT_CHAR('L');
                             LCD_PUT_CHAR('O');
                             LCD_PUT_CHAR('W');
                             LCD_PUT_CHAR('E');
                             LCD_PUT_CHAR('R');
                             LCD_PUT_CHAR(' ');
                             LCD_PUT_CMD(LCD_SECOND_LINE);
                             LCD_PUT_CHAR('S');
                             LCD_PUT_CHAR('O');
                             US_Delay(400000);
                         }
                         break;
                     case 6: // 6
                         if (state == 1){
                             LCD_PUT_CMD(LCD_FIRST_LINE);
                             LCD_PUT_CHAR('O');
                             LCD_PUT_CHAR('R');
                             LCD_PUT_CHAR('I');
                             LCD_PUT_CHAR('G');
                             LCD_PUT_CHAR('I');
                             LCD_PUT_CHAR('N');
                             LCD_PUT_CMD(LCD_SECOND_LINE);
                             LCD_PUT_CHAR('L');
                             LCD_PUT_CHAR('A');
                             US_Delay(400000);
                         }
                         else if(state == 2){
                             LCD_PUT_CMD(LCD_FIRST_LINE);
                             LCD_PUT_CHAR('H');
                             LCD_PUT_CHAR('I');
                             LCD_PUT_CHAR('G');
                             LCD_PUT_CHAR('H');
                             LCD_PUT_CHAR('E');
                             LCD_PUT_CHAR('R');
                             LCD_PUT_CMD(LCD_SECOND_LINE);
                             LCD_PUT_CHAR('L');
                             LCD_PUT_CHAR('A');
                             US_Delay(400000);
                         }
                         else if(state == 0){
                             LCD_PUT_CMD(LCD_FIRST_LINE);
                             LCD_PUT_CHAR('L');
                             LCD_PUT_CHAR('O');
                             LCD_PUT_CHAR('W');
                             LCD_PUT_CHAR('E');
                             LCD_PUT_CHAR('R');
                             LCD_PUT_CHAR(' ');
                             LCD_PUT_CMD(LCD_SECOND_LINE);
                             LCD_PUT_CHAR('L');
                             LCD_PUT_CHAR('A');
                             US_Delay(400000);
                           }

                      break;
                     case 10: // D
                         if (state == 1){
                             LCD_PUT_CMD(LCD_FIRST_LINE);
                             LCD_PUT_CHAR('O');
                             LCD_PUT_CHAR('R');
                             LCD_PUT_CHAR('I');
                             LCD_PUT_CHAR('G');
                             LCD_PUT_CHAR('I');
                             LCD_PUT_CHAR('N');
                             LCD_PUT_CMD(LCD_SECOND_LINE);
                             LCD_PUT_CHAR('S');
                             LCD_PUT_CHAR('I');
                             US_Delay(400000);
                         }
                         else if(state == 2){
                             LCD_PUT_CMD(LCD_FIRST_LINE);
                             LCD_PUT_CHAR('H');
                             LCD_PUT_CHAR('I');
                             LCD_PUT_CHAR('G');
                             LCD_PUT_CHAR('H');
                             LCD_PUT_CHAR('E');
                             LCD_PUT_CHAR('R');
                             LCD_PUT_CMD(LCD_SECOND_LINE);
                             LCD_PUT_CHAR('S');
                             LCD_PUT_CHAR('I');
                             US_Delay(400000);
                         }
                         else if(state == 0){
                             LCD_PUT_CMD(LCD_FIRST_LINE);
                             LCD_PUT_CHAR('L');
                             LCD_PUT_CHAR('O');
                             LCD_PUT_CHAR('W');
                             LCD_PUT_CHAR('E');
                             LCD_PUT_CHAR('R');
                             LCD_PUT_CHAR(' ');
                             LCD_PUT_CMD(LCD_SECOND_LINE);
                             LCD_PUT_CHAR('S');
                             LCD_PUT_CHAR('I');
                             US_Delay(400000);
                           }
                      break;
                     case 2:
                         if (state == 1){
                             LCD_PUT_CMD(LCD_FIRST_LINE);
                             LCD_PUT_CHAR('O');
                             LCD_PUT_CHAR('R');
                             LCD_PUT_CHAR('I');
                             LCD_PUT_CHAR('G');
                             LCD_PUT_CHAR('I');
                             LCD_PUT_CHAR('N');
                             LCD_PUT_CMD(LCD_SECOND_LINE);
                             LCD_PUT_CHAR('D');
                             LCD_PUT_CHAR('O');

                         US_Delay(400000);
                         }
                         else if(state == 2){
                             LCD_PUT_CMD(LCD_FIRST_LINE);
                             LCD_PUT_CHAR('H');
                             LCD_PUT_CHAR('I');
                             LCD_PUT_CHAR('G');
                             LCD_PUT_CHAR('H');
                             LCD_PUT_CHAR('E');
                             LCD_PUT_CHAR('R');
                             LCD_PUT_CMD(LCD_SECOND_LINE);
                             LCD_PUT_CHAR('D');
                             LCD_PUT_CHAR('O');
                             US_Delay(400000);
                         }
                         else if(state == 0){
                             LCD_PUT_CMD(LCD_FIRST_LINE);
                             LCD_PUT_CHAR('L');
                             LCD_PUT_CHAR('O');
                             LCD_PUT_CHAR('W');
                             LCD_PUT_CHAR('E');
                             LCD_PUT_CHAR('R');
                             LCD_PUT_CHAR(' ');
                             LCD_PUT_CMD(LCD_SECOND_LINE);
                             LCD_PUT_CHAR('D');
                             LCD_PUT_CHAR('O');
                             US_Delay(400000);

                         }

                      break;
                     case 5:
                         if (state == 1){
                             LCD_PUT_CMD(LCD_FIRST_LINE);
                             LCD_PUT_CHAR('O');
                             LCD_PUT_CHAR('R');
                             LCD_PUT_CHAR('I');
                             LCD_PUT_CHAR('G');
                             LCD_PUT_CHAR('I');
                             LCD_PUT_CHAR('N');
                             LCD_PUT_CMD(LCD_SECOND_LINE);
                             LCD_PUT_CHAR('R');
                             LCD_PUT_CHAR('E');

                         US_Delay(400000);
                         }
                         else if(state == 2){
                             LCD_PUT_CMD(LCD_FIRST_LINE);
                             LCD_PUT_CHAR('H');
                             LCD_PUT_CHAR('I');
                             LCD_PUT_CHAR('G');
                             LCD_PUT_CHAR('H');
                             LCD_PUT_CHAR('E');
                             LCD_PUT_CHAR('R');
                             LCD_PUT_CMD(LCD_SECOND_LINE);
                             LCD_PUT_CHAR('R');
                             LCD_PUT_CHAR('E');
                             US_Delay(400000);
                         }
                         else if(state == 0){
                             LCD_PUT_CMD(LCD_FIRST_LINE);
                             LCD_PUT_CHAR('L');
                             LCD_PUT_CHAR('O');
                             LCD_PUT_CHAR('W');
                             LCD_PUT_CHAR('E');
                             LCD_PUT_CHAR('R');
                             LCD_PUT_CHAR(' ');
                             LCD_PUT_CMD(LCD_SECOND_LINE);
                             LCD_PUT_CHAR('R');
                             LCD_PUT_CHAR('E');
                             US_Delay(400000);

                         }
                      break;
                    }






      }
      if (Read_SW(2)== 1 ){
          LCD_PUT_CMD(LCD_FIRST_LINE);

          LCD_PUT_CHAR(' ');
          LCD_PUT_CHAR(' ');
          LCD_PUT_CHAR(' ');
          LCD_PUT_CHAR(' ');
          LCD_PUT_CHAR(' ');
          LCD_PUT_CHAR(' ');
          LCD_PUT_CMD(LCD_SECOND_LINE);
          LCD_PUT_CHAR(' ');
          LCD_PUT_CHAR(' ');
          US_Delay(400000);
      }
      if(DTMF_flag==1)
      {
          if(old_digital != digital)
          {
          DTMF_count = 0;
          DTMF_flag = 0;
          }
      }
  }
}
//-------------------------------
// interrupt service routine #4
//-------------------------------
interrupt void INT4_ISR(void)
{
    if(DTMF_count < loop_time)
    {
       sample=10000*(sin(2.0*PI*DTMF_count*f/SAMPLING_FREQ));
       DTMF_count++;
    }
    else
    {
        sample = 0;
        DTMF_flag=1;
        old_digital = digital;
        DTMF_count = loop_time;
    }

    output_left_sample(sample);
    return;
}
interrupt void INT5_ISR(void){
    state = 0;
}
interrupt void INT6_ISR(void){
    state = 1;
}
interrupt void INT7_ISR(void){
    state = 2;
}
