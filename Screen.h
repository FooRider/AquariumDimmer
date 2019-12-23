#ifndef Screen_h
#define Screen_h

class Screen
{
	public:
		Screen();
		virtual void OnButtonClick();
		virtual void OnEncoderRotate(int steps);
		virtual void Loop();
};

#endif
