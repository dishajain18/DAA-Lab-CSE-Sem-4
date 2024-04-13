#include <lpc17xx.h>

unsigned int v1, x, i;
unsigned char row, var, flag, key, vtg[7], dval[7];
unsigned long int var1, temp, temp1, temp2, temp3, time;
unsigned char SCAN_CODE[16] = {0x11, 0x21, 0x41, 0x81,
                               0x12, 0x22, 0x42, 0x82,
                               0x14, 0x24, 0x44, 0x84,
                               0x18, 0x28, 0x48, 0x88};
unsigned char ASCII_CODE[16] = {'M', 'T', 'L', '\0',
                                 '0', '1', '2', '3',
                                 '4', '5', '6', '7',
                                 '8', '9', '\0', '='};
#define Ref_Vtg 3.300
#define Full_Scale 0xFFF // 12 bit ADC
unsigned long adc_temp;
float in_vtg;

void lcd_init(void);
void write(int, int);
void delay(unsigned int);
void lcd_comdata(int, int);
void clear_ports(void);
void lcd_puts(unsigned char *);

void lcd_init() {
    /*Ports initialized as GPIO */
			LPC_PINCON->PINSEL1 &= 0xFC003FFF; //P0.23 to P0.28
			/*Setting the directions as output */
			LPC_GPIO0->FIODIR |= 0x0F<<23 | 1<<27 | 1<<28;
			clear_ports();
			delay(200);
			lcd_comdata(0x33, 0);
			delay(300);
			lcd_comdata(0x32, 0);
			delay(300);
			lcd_comdata(0x28, 0); //function set
			delay(300);
			lcd_comdata(0x0c, 0);//display on cursor off
			delay(800);
			lcd_comdata(0x06, 0); //entry mode set increment cursor right
			delay(800);
			lcd_comdata(0x01, 0); //display clear
			delay(1000);
			return;
}

void lcd_comdata(int temp1, int type) {
    int temp2 = temp1 & 0xf0; // move data (26-8+1) times : 26 - HN place, 4 - Bits
    temp2 = temp2 << 19;      // data lines from 23 to 26
    write(temp2, type);
    temp2 = temp1 & 0x0f; // 26-4+1
    temp2 = temp2 << 23;
    write(temp2, type);
    delay(1000);
    return;
}

void write(int temp2, int type) { /* write to command/data reg */
    clear_ports();
    LPC_GPIO0->FIOPIN = temp2; // Assign the value to the data lines
    if (type == 0)
        LPC_GPIO0->FIOCLR = 1 << 27; // clear bit RS for Command
    else
        LPC_GPIO0->FIOSET = 1 << 27; // set bit RS for Data
    LPC_GPIO0->FIOSET = 1 << 28;    // EN=1
    delay(25);
    LPC_GPIO0->FIOCLR = 1 << 28; // EN =0
    return;
}

void inittime0() {
    LPC_TIM0->CTCR = 0x0;
    LPC_TIM0->TCR = 0x2;
    LPC_TIM0->PR = 2999;
}

void delay(unsigned int milliseconds) {
    LPC_TIM0->TCR = 0x2;
    LPC_TIM0->TCR = 0x1;
    while (LPC_TIM0->TC < milliseconds);
    LPC_TIM0->TCR = 0x0;
}

void clockwise() {
    v1 = 0x8;
    for (i = 0; i < 4; i++) {
        v1 = v1 << 1;
        LPC_GPIO0->FIOPIN = v1;
        delay(10000);
    }
}

void anti_clockwise() {
    v1 = 0x100;
    for (i = 0; i < 4; i++) {
        v1 = v1 >> 1;
        LPC_GPIO0->FIOPIN = v1;
        delay(10000);
    }
}

void Match(int milliseconds) {
    LPC_TIM0->MR0 = milliseconds;
    LPC_TIM0->MCR = 2;
    LPC_TIM0->EMR = 0x20;
    LPC_TIM0->TCR = 0x2;
    LPC_TIM0->TCR = 0x1;
	  LPC_GPIO1->FIODIR=1<<23;
	  LPC_GPIO1->FIOPIN=0<<23;
    while (!(LPC_TIM0->EMR & 1));
	   //delay(milliseconds);
    LPC_TIM0->TCR = 0x0;
	  
	  LPC_GPIO1->FIOPIN=1<<23;
    for (i = 0; i < 400; i++)
        clockwise();
}

void clear_ports(void) { /* Clearing the lines at power on */
    LPC_GPIO0->FIOCLR = 0x0F << 23; // Clearing data lines
    LPC_GPIO0->FIOCLR = 1 << 27;    // Clearing RS line
    LPC_GPIO0->FIOCLR = 1 << 28;    // Clearing Enable line
    return;
}

void manual(void) {
    while (1) {
        x = LPC_GPIO2->FIOPIN >> 12;
        x &= 1;
        if (x == 1)
            clockwise();
        else if (x == 0)
            anti_clockwise();
    }
}

void scan(void) {
    temp3 = LPC_GPIO0->FIOPIN;
    temp3 &= (0XF << 15);
    if (temp3 != 0x00000000) {
        flag = 1;
        temp3 >>= 11; // 15-4
        temp >>= 19;
        key = temp3 | temp;
    }
}

void settime() {
    LPC_GPIO0->FIODIR |= 0x0F << 23 | 1 << 27 | 1 << 28; // LCD
    clear_ports();
    delay(30);
    
    lcd_comdata(0xC0, 0); // point to first line of LCD
    delay(800);
    while (1) {
        for (row = 2; row < 5; row++) {
            if (row == 2)
                var1 = 1 << 20;
            else if (row == 3)
                var1 = 1 << 21;
            else if (row == 4)
                var1 = 1 << 22;
            temp = var1;
            LPC_GPIO0->FIOCLR = 0x00780000; // first clear the
            LPC_GPIO0->FIOSET = var1;        // enabling the row
            flag = 0;
            scan(); // scan if any key pressed in the enabled row
            if (flag == 1)
                break;
        } // end for
        if (flag == 1)
            break;
    } // 2nd while(1)
    for (i = 0; i < 16; i++) // get the ascii code for display
    {
        if (key == SCAN_CODE[i]) {
            key = ASCII_CODE[i];
            break;
        } // end if(key == SCAN_CODE[i])
    }     // end for(i=0;i<16;i++)
    lcd_puts(&key);
    key = key - 48;
    //time = key * 3600 * 1000;
		time = key * 1000;
    Match(time);
}

void lcd_puts(unsigned char *buf1) {
    unsigned int i = 0;
    unsigned int temp3;
    while (buf1[i] != '\0') {
        temp3 = buf1[i];
        lcd_comdata(temp3, 1);
        i++;
        if (i == 16) {
            lcd_comdata(0xc0, 0);
        }
    }
    return;
}

void light(void) {
    LPC_SC->PCONP |= (1 << 12);
    LPC_PINCON->PINSEL3 |= 0xC0000000; // P1.31 as AD0.5

    LPC_ADC->ADCR = (1 << 5) | (1 << 21) | (1 << 24); // 0x01200001;
                                                     // ADC0.5, start conversion and operational
    while (!(LPC_ADC->ADDR5 & 0x80000000))
        ;
    // wait till 'done' bit is 1, indicates conversion complete

    adc_temp = LPC_ADC->ADDR5;
    adc_temp >>= 4;
    adc_temp &= 0x00000FFF; // 12 bit ADC
    in_vtg = (((float)adc_temp * (float)Ref_Vtg)) / ((float)Full_Scale);
    // calculating input analog voltage
    for (i = 0; i < 2000; i++)
        ;
    if (in_vtg > 0.7) {
        for (i = 0; i < 200; i++)
            anti_clockwise();
    }
    // if this in_vtg is above a certain value then close blinds
    for (i = 0; i < 7; i++)
        vtg[i] = dval[i] = 0x00;
    adc_temp = 0;
    in_vtg = 0;
}
unsigned char a[]="Start";
int main(void) {
	  SystemInit();
	  SystemCoreClockUpdate();
    LPC_PINCON->PINSEL0 = 0X0; // p0.4 to p0.7
    LPC_PINCON->PINSEL4 = 0X0; // SWITCH P2.12
    LPC_GPIO2->FIODIR = 0 << 12;
    LPC_GPIO0->FIODIR |= 0xf << 4 | 0xf << 19 | 0x0 << 15; // made output P0.19 to P0.22 (rows)
	                                                         // made input P0.15 to P0.18(cols)
    inittime0();
	  lcd_init();
	  
	  lcd_puts(&a[0]);
    while (1) {
        var1 = 1 << 19;
        temp = var1;
        LPC_GPIO0->FIOCLR = 0xF << 19;
        LPC_GPIO0->FIOSET = var1;
        flag = 0;
        scan();
        if (flag == 1)
            break;
    }
    for (i = 0; i < 4; i++) {
        if (key == SCAN_CODE[i]) {
            key = ASCII_CODE[i];
            break;
        }
    }

    switch (key) {
    case 'M':
        manual();
        break;

    case 'T':
        settime();
        break;
    case 'L':
        light();
        break;
    default:
        break;
    }
		
}
