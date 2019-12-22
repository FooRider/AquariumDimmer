#ifndef Screen_h
#define Screen_h

class Screen
{
	public:
		Screen();
		virtual void ButtonClick();
		virtual void EncoderRotate(int steps);
		virtual void Loop();
};

#endif
