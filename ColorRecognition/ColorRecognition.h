/**
 * Arduino - Color Recognition Sensor
 * 
 * ColorRecognition.h
 * 
 * The abstract class for the color recognition sensors.
 * 
 * @author Dalmir da Silva <dalmirdasilva@gmail.com>
 */

#ifndef __ARDUINO_DRIVER_COLOR_RECOGNITION_H__
#define __ARDUINO_DRIVER_COLOR_RECOGNITION_H__ 1

class ColorRecognition {
public:

    /**
     * Returns the red color intensity.
     * 
     * @retun               The red color intensity.
     */
    virtual unsigned char getRed() = 0;

    /**
     * Returns the green color intensity.
     * 
     * @retun               The green color intensity.
     */
    virtual unsigned char getGreen() = 0;

    /**
     * Returns the blue color intensity.
     * 
     * @retun               The blue color intensity.
     */
    virtual unsigned char getBlue() = 0;

    /**
     * Returns the blue color intensity.
     * 
     * @retun               The blue color intensity.
     */
    virtual bool fillRGB(unsigned char buf[3]) = 0;
};

#endif /* __ARDUINO_DRIVER_COLOR_RECOGNITION_H__ */
