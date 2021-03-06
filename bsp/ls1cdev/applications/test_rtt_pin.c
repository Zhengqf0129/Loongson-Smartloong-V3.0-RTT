/*
file: test_pin.c
测试pin驱动， 在finsh 中运行
1. test_pin(52)   GPIO52引脚每隔1秒输出电平翻转
 */

#include <rtthread.h>
#include <stdlib.h>  
#include <drivers/pin.h>
#include "../drivers/drv_gpio.h"
void test_pin(rt_uint8_t pin_led )  
{
    // pin初始化
    hw_pin_init();

    // 把相应gpio设为输出模式
    rt_pin_mode(pin_led, PIN_MODE_OUTPUT);
    
    while (1)  
    {
        rt_pin_write(pin_led, PIN_LOW);
        rt_thread_delay(1 * RT_TICK_PER_SECOND);  

        rt_pin_write(pin_led, PIN_HIGH);
        rt_thread_delay(1 * RT_TICK_PER_SECOND);
    }  
}  

void test_pin_msh(int argc, char** argv)
{
    unsigned int num;
	num = strtoul(argv[1], NULL, 0);
	test_pin(num);
}

 #include  <finsh.h> 
FINSH_FUNCTION_EXPORT(test_pin , test_pin led-gpio52 e.g.test_pin(52));
/* 导出到 msh 命令列表中 */
MSH_CMD_EXPORT(test_pin_msh, test_pin 52);
