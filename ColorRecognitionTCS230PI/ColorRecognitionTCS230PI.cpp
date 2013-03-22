/**
 * Arduino - Color Recognition Sensor
 * 
 * ColorRecognitionTCS230PI.h
 * 
 * The abstract class for the Color Recognition TCS230 sensor.
 * 
 * @author Dalmir da Silva <dalmirdasilva@gmail.com>
 */

#ifndef __ARDUINO_DRIVER_COLOR_RECOGNITION_TCS230PI_CPP__
#define __ARDUINO_DRIVER_COLOR_RECOGNITION_TCS230PI_CPP__ 1

#include "ColorRecognitionTCS230PI.h"

ColorRecognitionTCS230PI::ColorRecognitionTCS230PI(unsigned char outPin,
        unsigned char s2Pin, unsigned char s3Pin) {
    this->s2Pin = s2Pin;
    this->s3Pin = s3Pin;
    this->outPin = outPin;
    pinMode(s2Pin, OUTPUT);
    pinMode(s3Pin, OUTPUT);
    pinMode(outPin, INPUT);
    for (unsigned char i = 0; i < 3; i++) {
        minFrequency[i] = 0;
        maxFrequency[i] = 1000;
    }
}

void ColorRecognitionTCS230PI::adjustWhiteBalance() {
    for (unsigned char i = 0; i < 3; i++) {
        setFilter((Filter) i);
        maxFrequency[i] = getFrequency(255);
    }
}

void ColorRecognitionTCS230PI::adjustBlackBalance() {
    for (unsigned char i = 0; i < 3; i++) {
        setFilter((Filter) i);
        minFrequency[i] = getFrequency(255);
    }
}

unsigned char ColorRecognitionTCS230PI::getRed() {
    setFilter(RED_FILTER);
    return (unsigned char) map(getFrequency(SAMPLES), minFrequency[0], maxFrequency[0], 0, 255);
}

unsigned char ColorRecognitionTCS230PI::getGreen() {
    setFilter(GREEN_FILTER);
    return (unsigned char) map(getFrequency(SAMPLES), minFrequency[1], maxFrequency[1], 0, 255);
}

unsigned char ColorRecognitionTCS230PI::getBlue() {
    setFilter(BLUE_FILTER);
    return (unsigned char) map(getFrequency(SAMPLES), minFrequency[2], maxFrequency[2], 0, 255);
}

bool ColorRecognitionTCS230PI::fillRGB(unsigned char buf[3]) {
    buf[0] = getRed();
    buf[1] = getGreen();
    buf[2] = getBlue();
    return true;
}

void ColorRecognitionTCS230PI::setFilter(Filter filter) {
    unsigned char s2 = LOW, s3 = LOW;
    if (filter == CLEAR_FILTER || filter == GREEN_FILTER) {
        s2 = HIGH;
    }
    if (filter == BLUE_FILTER || filter == GREEN_FILTER) {
        s3 = HIGH;
    }
    digitalWrite(s2Pin, s2);
    digitalWrite(s3Pin, s3);
}

long ColorRecognitionTCS230PI::getFrequency(unsigned int samples) {
    long frequency = 0;
    for (unsigned int i = 0; i < samples; i++) {
        frequency += 500000 / pulseIn(outPin, HIGH, 250000);
    }
    return frequency / samples;
}

#endif /* __ARDUINO_DRIVER_COLOR_RECOGNITION_TCS230PI_CPP__ */
