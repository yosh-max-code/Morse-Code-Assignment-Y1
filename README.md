# Arduino Morse Code Translator

A C-based program for Arduino Uno that translates text input into visual Morse code output using LED arrays.

## Overview

This project converts alphanumeric characters into Morse code sequences and displays them through LED patterns. The program reads text input from the serial monitor and outputs the corresponding Morse code signals with accurate timing for dots, dashes, and spacing.

## Features

- **ASCII Character Mapping**: Converts standard alphanumeric input into Morse code equivalents
- **LED Visual Output**: Displays Morse code through LED array with distinct patterns for dots and dashes
- **Real-time Processing**: Reads serial input and immediately translates to Morse code
- **Accurate Timing**: Implements proper Morse code timing ratios for dots, dashes, and pauses

## Hardware Requirements

- Arduino Uno microcontroller
- LED array (or single LED for basic implementation)
- Appropriate resistors for LEDs
- Breadboard and connecting wires
- USB cable for serial communication

## Technical Implementation

### Core Functionality

The program implements:
- **ASCII to Morse Mapping**: Character-to-code conversion system
- **Timing Control**: Precise duration control for dot/dash signals

### Programming Concepts

- Low-level C programming for embedded systems
- Direct hardware manipulation through Arduino
- Character encoding and ASCII value processing
- Timing algorithms for LED control patterns

## How to Use

1. **Setup**:
   - Connect LEDs to appropriate Arduino pins
   - Upload the program to your Arduino Uno
   - Open the Serial Monitor in Arduino IDE

2. **Operation**:
   - Type text into the Serial Monitor
   - Press Enter to send
   - Watch the LED array display the Morse code translation

3. **Input**:
   - Accepts alphanumeric characters (A-Z, 0-9)
   - Spaces between words are recognized
   - Invalid characters may be skipped or trigger error handling

## Example

**Input**: `HELLO`

**Output**: 
```
H: .... (4 dots)
E: . (1 dot)
L: .-.. (dot-dash-dot-dot)
L: .-.. (dot-dash-dot-dot)
O: --- (3 dashes)
```

## Academic Context

This project was completed as part of coursework at Aberystwyth University, demonstrating practical application of:
- Embedded systems programming
- Hardware-software integration
- Real-time signal processing
- C language proficiency

## Future Improvements

Potential enhancements could include:
- Audio output alongside visual
- Adjustable speed settings
- Support for additional characters/symbols
- Two-way communication (Morse to text decoding)
- Multi-LED patterns for clearer visualization

## License

Academic project - see university guidelines for usage restrictions.

## Author

**Yash Singh**  
Computer Science and Artificial Intelligen
