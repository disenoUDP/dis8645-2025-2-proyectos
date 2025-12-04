#ifndef MOTOR_MARVEL_H
#define MOTOR_MARVEL_H

#include <Arduino.h>

class MotorMarvel{
public: 
int able;
int input1;
int input2;
bool abrazo=false;

motorMarvel(int able, int in1, int in2);

void setear();

void abrazar();

void tersiana();
};

#endif