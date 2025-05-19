# SanitiServe – Automated Sanitary Napkin Dispenser

## Overview
SanitiServe is an Arduino-based automated sanitary napkin dispenser designed to improve hygiene access in public and private spaces. It dispenses napkins on-demand and alerts users when stock is low.

## Features
- Dispenses a single napkin using a servo motor
- Monitors stock level with an IR sensor
- Displays "Please Refill" alert on an LCD when low
- Simple button-based user trigger

## Components
- Arduino Uno
- Servo Motor
- IR Sensor
- 16x2 I2C LCD
- Push Button
- Power Supply

## Communication Protocols
- **GPIO**: For IR sensor and button input
- **I2C**: For LCD display communication

## Usage
1. Upload code to Arduino.
2. Power the system.
3. Press the button to dispense a napkin.
4. Refill when "Please Refill" alert appears.

