#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <emu8086.h>
#include <assembler.h>


extern int errors;
extern struct *list_err;

int main () {
     struct emu8086 *aCPU = emu8086_new();
     op_setptrs(aCPU);
     do_assembly(aCPU, "test.asm");
     assembler_step = 1;
     do_assembly(aCPU, "test.asm");
  
    if(erros > 0) {
    printf("Failed to compile code, %s", list_err->message );
      return 1;
    
    }
     CS = aCPU->code_start_addr / 0x10;
     DS = 0x03ff;
     _SS = ((CS * 0x10) - 0x20000) / 0x10;
     while (IP < aCPU->end_address - 1)
     {
         int op = *(CODE_SEGMENT_IP), handled = 0;

         aCPU->op[op](aCPU, &handled);
         if (!handled)
         {
             char buf[15];
             sprintf(buf, "Unhandled instrution on line %d, opcode: %x", _INSTRUCTIONS->line_number, op); //message()
             message(buf, ERR);
         }
         if (aCPU->skip_next)
             aCPU->skip_next = 1;
         else if (_INSTRUCTIONS->next != NULL)
             _INSTRUCTIONS = _INSTRUCTIONS->next;
         if (IP > 0xffff)
         {
             IP = IP - 0xffff;
             CS = CS - 0x10000;
         }
         handled = 0;

       dump_registers(aCPU);
     }
return 0;
 }
