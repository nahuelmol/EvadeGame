
struct Button_State {
	bool is_down;
	bool changed;
};

enum {
	BUTTON_UP,
	BUTTON_DOWN,
	BUTTON_LEFT,
	BUTTON_RIGHT,

	BUTTON_COUNT,
};

struct Input {
	float pos_x = 0;
    float pos_y = 0;
    
    std::string numbuffer = "";

    Button_State buttons[BUTTON_COUNT];
};
