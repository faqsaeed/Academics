import pyautogui as auto
import time

time.sleep(5)  # Gives you 5 seconds to switch to WhatsApp Web tab

while True:
    auto.write("bro??") # Type the message
    auto.press("enter") # Press Enter to send the message
    time.sleep(1)  # Wait for 1 second before sending the next message
