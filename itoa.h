#include <iostream>

using namespace std;

void reverse_string(char word[], int len){
  int _start=0;
  int _end=len-1;
  while(_start<_end){
    swap(*(word+_start),*(word+_end));
    ++_start;
    --_end;
  }
}

char* itoa(int score, char* word){
  int i = 0;
  if (score==0){
    word[i++]='0';
    word[i]='\0';
  }
  int rest;
  while(score!=0){
    rest = score % 10;
    word[i++] = '0' + rest;
    score = score / 10;
  }
  word[i] = '\0';
  reverse_string(word,i);
  return word;
}
