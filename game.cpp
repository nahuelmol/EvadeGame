
internal void 
simulate_game(Input *input){
    using std::cout;
    using std::endl;

    cout << "nbuffer:" << input->numbuffer << endl;
    int step = 1;
    if(input->buttons[BUTTON_UP].is_down){
        if((input->numbuffer) == ""){
            (input->pos_y)+=1;
        } else {
            step = stoi(input->numbuffer);
            (input->pos_y)+=step;
        }
    }

    if(input->buttons[BUTTON_DOWN].is_down){
        if((input->numbuffer) == ""){
            (input->pos_y)-=1;
        } else {
            step = stoi(input->numbuffer);
            (input->pos_y)-=step;
        }
    }
    
    if(input->buttons[BUTTON_LEFT].is_down){
        if((input->numbuffer) == ""){
            (input->pos_x)-=1;
        } else {
            step = stoi(input->numbuffer);
            (input->pos_x)-=step;
        }
    }
	
    if(input->buttons[BUTTON_RIGHT].is_down){
        if((input->numbuffer) == ""){
            (input->pos_x)+=1;
        } else {
            step = stoi(input->numbuffer);
            (input->pos_x)+=step;
        }
    }
    
    clear_screen(0xff5500);
	draw_rect(input->pos_x, input->pos_y, 1, 1, 0x7611c3);
}

