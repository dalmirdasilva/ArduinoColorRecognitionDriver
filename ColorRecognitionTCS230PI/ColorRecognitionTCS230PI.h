/**
 * Arduino - Color Recognition Sensor
 * 
 * ColorRecognitionTCS230PI.h
 * 
 * The abstract class for the Color Recognition TCS230 sensor.
 * 
 * @author Dalmir da Silva <dalmirdasilva@gmail.com>
 */

#ifndef __ARDUINO_DRIVER_COLOR_RECOGNITION_TCS230_PI_H__
#define __ARDUINO_DRIVER_COLOR_RECOGNITION_TCS230_PI_H__ 1

#include <Arduino.h>
#include <ColorRecognition.h>

/**
 * In this driver we are assuming the S0 pin is LOW and S1 pin is HIGH. With
 * output frequency at 2%. It saves arduino pins also.
 * 
 * <pre>
 * S0   S1  OUTPUT FREQUENCY
 * L    L   Power down
 * L    H   2%
 * H    L   20%
 * H    H   100%
 * </pre>
 * 
 * Also we are assuming the OE pin is LOW, this pin controls the device 
 * activation. If OE is LOW the device is enable.
 * 
 * Output frequency scaling:
 * 
 * Output-frequency scaling is controlled by two logic inputs, S0 and S1. The 
 * internal light-to-frequency converter generates a fixed-pulsewidth pulse 
 * train. Scaling is accomplished by internally connecting the pulse-train 
 * output of the converter to a series of frequency dividers. Divided outputs 
 * are 50%-duty cycle square waves with relative frequency values of 100%, 20%, 
 * and 2%. Because division of the output frequency is accomplished by counting 
 * pulses of the principal internal frequency, the final-output period 
 * represents an average of the multiple periods of the principle frequency.
 * 
 * The output-scaling counter registers are cleared upon the next pulse of the 
 * principal frequency after any transition of the S0, S1, S2, S3, and OE lines.
 * The output goes high upon the next subsequent pulse of the principal 
 * frequency, beginning a new valid period. This minimizes the time delay 
 * between a change on the input lines and the resulting new output period. The 
 * response time to an input programming change or to an irradiance step change 
 * is one period of new frequency plus 1 µS. The scaled output changes both the 
 * full–scale frequency and the dark frequency by the selected scale factor. The 
 * frequency-scaling function allows the output range to be optimized for a 
 * variety of measurement techniques. The scaled-down outputs may be used where 
 * only a slower frequency counter is available, such as low-cost 
 * microcontroller, or where period measurement techniques are used.
 * 
 * Measuring the frequency:
 * 
 * The choice of interface and measurement technique depends on the desired 
 * resolution and data acquisition rate. For maximum data-acquisition rate, 
 * period-measurement techniques are used. Output data can be collected at a 
 * rate of twice the output frequency or one data point every microsecond for 
 * full-scale output. Period measurement requires the use of a fast reference 
 * clock with available resolution directly related to reference clock rate. 
 * Output scaling can be used to increase the resolution for a given clock rate 
 * or to maximize resolution as the light input changes. Period measurement is 
 * used to measure rapidly varying light levels or to make a very fast 
 * measurement of a constant light source. Maximum resolution and accuracy may 
 * be obtained using frequency-measurement, pulse-accumulation, or integration 
 * techniques. Frequency measurements provide the added benefit of averaging out 
 * random- or high-frequency variations (jitter) resulting from noise in the 
 * light signal. Resolution is limited mainly by available counter registers and 
 * allowable measurement time. Frequency measurement is well suited for slowly 
 * varying or constant light levels and for reading average light levels over 
 * short periods of time. Integration (the accumulation of pulses over a very 
 * long period of time) can be used to measure exposure, the amount of light 
 * present in an area over a given time period. 
 */

#define SAMPLES   32

class ColorRecognitionTCS230PI : public ColorRecognition {
private:

    /**
     * The s2 pin.
     */
    unsigned char s2Pin;

    /**
     * The s3 pin.
     */
    unsigned char s3Pin;

    /**
     * The out pin.
     */
    unsigned char outPin;

    /**
     * The minimum frequency.
     */
    long minFrequency[3];

    /**
     * The maximum frequency.
     */
    long maxFrequency[3];

public:

    /**
     * Filter color enumeration.
     */
    enum Filter {
        RED_FILTER, GREEN_FILTER, BLUE_FILTER, CLEAR_FILTER
    };

    /**
     * Private constructor.
     */
    ColorRecognitionTCS230PI(unsigned char outPin, unsigned char s2Pin,
            unsigned char s3Pin);

    /**
     * Store the current read as the minimum frequency for each color.
     * 
     * It tells what is considered black.
     */
    void adjustWhiteBalance();

    /**
     * Store the current read as the maximum frequency for each color.
     * 
     * It tells what is considered white.
     */
    void adjustBlackBalance();

    /**
     * Returns the red color intensity.
     * 
     * @retun               The red color intensity.
     */
    unsigned char getRed();

    /**
     * Returns the green color intensity.
     * 
     * @retun               The green color intensity.
     */
    unsigned char getGreen();

    /**
     * Returns the blue color intensity.
     * 
     * @retun               The blue color intensity.
     */
    unsigned char getBlue();

    /**
     * Returns the blue color intensity.
     * 
     * @retun               The blue color intensity.
     */
    bool fillRGB(unsigned char buf[3]);

    /**
     * Gets the frequency from the out pin.
     * 
     * NOTE: It uses pulseIn, collects some samples and calculate the frequency.
     * 
     * 
     * The out pin generates a square wave, we sum the times between the raise 
     * edge and divide by the number of samples.
     * 
     * <pre>
     *        1       2       3
     * ----   -----   -----   -----
     *    |   |   |   |   |   |
     *    -----   -----   -----
     * </pre>
     * 
     * @return          The pin frequency.
     */
    long getFrequency(unsigned int samples);

    /**
     * Sets the s2 and s3 pins according of the color passed as filter.
     * 
     * <pre>
     * S2   S3  PHOTODIODE TYPE
     * L    L   Red
     * L    H   Blue
     * H    L   Clear (no filter)
     * H    H   Green
     * </pre>
     * 
     * @param filter        The next filter.
     */
    void setFilter(Filter filter);

};

#endif /* __ARDUINO_DRIVER_COLOR_RECOGNITION_TCS230_PI_H__ */
