//here will be basic functions of stacks
#include<stdio.h>
bool isempty(int top)
{
  if(top==-1)
    return true;
  else
    return false;
}
bool isfull(int top,int max)
{
  if(top==max)
    return true;
  else
    return false;
}
