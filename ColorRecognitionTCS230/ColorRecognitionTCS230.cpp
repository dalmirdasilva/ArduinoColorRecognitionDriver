/**
 * Arduino - Color Recognition Sensor
 * 
 * ColorRecognitionTCS230.h
 * 
 * The abstract class for the Color Recognition TCS230 sensor.
 * 
 * @author Dalmir da Silva <dalmirdasilva@gmail.com>
 */

#ifndef __ARDUINO_DRIVER_COLOR_RECOGNITION_TCS230_CPP__
#define __ARDUINO_DRIVER_COLOR_RECOGNITION_TCS230_CPP__ 1

#include "ColorRecognitionTCS230.h"

ColorRecognitionTCS230 ColorRecognitionTCS230::instance;

void ColorRecognitionTCS230::initialize(unsigned char outPin,
        unsigned char s2Pin, unsigned char s3Pin) {
    this->s2Pin = s2Pin;
    this->s3Pin = s3Pin;
    this->outPin = outPin;
    this->currentFilter = CLEAR_FILTER;
    pinMode(s2Pin, OUTPUT);
    pinMode(s3Pin, OUTPUT);
    pinMode(outPin, INPUT);
    Timer1.initialize();
    Timer1.attachInterrupt(ColorRecognitionTCS230::timerInterruptHandler);
    attachInterrupt((outPin - 2), ColorRecognitionTCS230::externalInterruptHandler, RISING);
}

void ColorRecognitionTCS230::adjustWhiteBalance() {
    delay(4000);
    instance.whiteBalanceFrequencies[0] = instance.lastFrequencies[0];
    instance.whiteBalanceFrequencies[1] = instance.lastFrequencies[1];
    instance.whiteBalanceFrequencies[2] = instance.lastFrequencies[2];
}

void ColorRecognitionTCS230::externalInterruptHandler() {
    instance.count++;
}

void ColorRecognitionTCS230::timerInterruptHandler() {
    switch (instance.currentFilter) {
        case CLEAR_FILTER:
            setFilter(RED_FILTER);
            break;
        case RED_FILTER:
            instance.lastFrequencies[0] = instance.count;
            setFilter(GREEN_FILTER);
            break;
        case GREEN_FILTER:
            instance.lastFrequencies[1] = instance.count;
            setFilter(BLUE_FILTER);
            break;
        case BLUE_FILTER:
            instance.lastFrequencies[2] = instance.count;
            setFilter(RED_FILTER);
            break;
    }
    instance.count = 0;
    Timer1.setPeriod(1000000);
}

unsigned char ColorRecognitionTCS230::getRed() {
    return (unsigned char) map(lastFrequencies[0], 0, whiteBalanceFrequencies[0], 0, 255);
}

unsigned char ColorRecognitionTCS230::getGreen() {
    return (unsigned char) map(lastFrequencies[1], 0, whiteBalanceFrequencies[1], 0, 255);
}

unsigned char ColorRecognitionTCS230::getBlue() {
    return (unsigned char) map(lastFrequencies[2], 0, whiteBalanceFrequencies[2], 0, 255);
}

bool ColorRecognitionTCS230::fillRGB(unsigned char buf[3]) {
    buf[0] = getRed();
    buf[1] = getGreen();
    buf[2] = getBlue();
    return true;
}

void ColorRecognitionTCS230::setFilter(Filter filter) {
    unsigned char s2 = LOW, s3 = LOW;
    instance.currentFilter = filter;
    if (filter == CLEAR_FILTER || filter == GREEN_FILTER) {
        s2 = HIGH;
    }
    if (filter == BLUE_FILTER || filter == GREEN_FILTER) {
        s3 = HIGH;
    }
    digitalWrite(instance.s2Pin, s2);
    digitalWrite(instance.s3Pin, s3);
}

#endif /* __ARDUINO_DRIVER_COLOR_RECOGNITION_TCS230_CPP__ */
