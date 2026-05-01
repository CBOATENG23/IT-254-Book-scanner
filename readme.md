This project comprises a machine-learning, computer vision-based, and AI-assisted recommendation system using Arduino board.

A webcam will capture an image of the book, and the system will identify the book using TensorFlow/Teachable Machine (i.e., Hunger Games, Percy Jackson). Then, the Arduino will measure the mood (low, medium, or high) from the user's potentiometer reading and request scanning of the book via serial communication. The recommendation function will output suggestions according to the book and mood.

Results will be communicated back to the Arduino and feedback will be provided using LEDs and buzzer, according to the number of recommendations.

Tech Used Python Arduino (C/C++)

Hardware Arduino, button, potentiometer LEDs, buzzer Webcam
