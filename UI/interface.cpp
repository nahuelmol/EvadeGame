#include <vector>
#include "utils.cpp"

class NPC {
	public:
		float xlocation, ylocation;
		int level;
		void* memory;
		BITMAPINFO bitmap_info;

		int height, width;

		NPC (){
			this -> xlocation = xlocation;
			this -> ylocation = ylocation;
			this -> level = level;
		}
};


class Render_State : public NPC {
	public:
		int height, width;
    	void* memory;

    	BITMAPINFO bitmap_info;
};


const char g_szClassName[] = "GAME CLASS";

global_variable bool running = true;

global_variable Render_State render_state;

#include "platform.cpp"
#include "builder.cpp"
#include "game.cpp"

std::vector<Nova*> Novas;
std::vector<Killer*> Killers;

void InitializeDebuggerConsole(){
	AllocConsole();
	freopen("CONOUT$", "w", stdout);
}

Input input = {};
char* buffer = new char[10];

LRESULT CALLBACK wnd_simulator(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam ){

    using std::cout;
    using std::endl;

    switch(msg){
        case WM_CLOSE:
        case WM_DESTROY: {
            running = false;
        } break;
        case WM_KEYDOWN: 
        {
            if(wparam >= 48 && wparam <= 57){
                char digit = static_cast<char>(wparam);
                std::string mystr(1,digit);
                
                input.numbuffer += mystr;

            } else if(wparam == 65) {
                
                Nova* mynova = new Nova();
                mynova->setProps(0,0,4,4);

                Novas.push_back(mynova);
                size_t index = Novas.size();
                mynova->setID(index);
                //if(novas_count >= 10){
                //    cout << "you have reached the maximum enemies per level" << endl;
                //}
            } else if(wparam >= 73 && wparam <= 76){
                size_t novasize = Novas.size();
                if(novasize > 0){
                    if(wparam == 'J'){
                        Novas[0]->buttons[BUTTON_J].is_down = true;
                    }    
                    
                    if(wparam == 'K'){
                        Novas[0]->buttons[BUTTON_K].is_down = true;
                    } 
                    
                    if(wparam == 'I'){
                        Novas[0]->buttons[BUTTON_I].is_down = true;
                    }

                    if(wparam == 'L'){
                        Novas[0]->buttons[BUTTON_L].is_down = true;
                    }       
                }

            } else {
                
                switch(wparam){
                    case VK_UP:
                        input.buttons[BUTTON_UP].is_down = true;
                        input.buttons[BUTTON_UP].changed = true;
                    break;

                    case VK_DOWN:
                        input.buttons[BUTTON_DOWN].is_down = true;
                    break;

                    case VK_LEFT:
                        input.buttons[BUTTON_LEFT].is_down = true;
                    break;

                    case VK_RIGHT:
                        input.buttons[BUTTON_RIGHT].is_down = true;
                    break;
                }
            }
                
        } break;
        case WM_KEYUP:
        {
            if(wparam >= 73 && wparam <= 76){
                size_t novasize = Novas.size();
                if(novasize > 0){
                    if(wparam == 'J'){
                        Novas[0]->buttons[BUTTON_J].is_down = false;
                    }
                
                    if(wparam == 'K'){
                        Novas[0]->buttons[BUTTON_K].is_down = false;
                    }

                    if(wparam == 'I'){
                        Novas[0]->buttons[BUTTON_I].is_down = false;
                    }

                    if(wparam == 'L'){
                        Novas[0]->buttons[BUTTON_L].is_down = false;
                    }
                }
            } else {

                switch(wparam){
                    case VK_UP:
                    {
                        input.buttons[BUTTON_UP].is_down = false;
                        input.numbuffer = "";
                    } break;

                    case VK_DOWN:
                        input.buttons[BUTTON_DOWN].is_down = false;
                        input.numbuffer = "";
                    break;

                    case VK_LEFT:
                        input.buttons[BUTTON_LEFT].is_down = false;
                        input.numbuffer = "";
                    break;

                    case VK_RIGHT:
                        input.buttons[BUTTON_RIGHT].is_down = false;
                        input.numbuffer = "";
                    break;
                }
            }
        } break;
        case WM_SIZE:
        {

            RECT rect;
            GetClientRect(hwnd, &rect);

            render_state.width = rect.right - rect.left;
            render_state.height = rect.bottom - rect.top;
            
            int size = render_state.width * render_state.height * sizeof(unsigned int);

            if(render_state.memory) VirtualFree(render_state.memory,0 , MEM_RELEASE);

            render_state.memory = VirtualAlloc(0, size, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);

            render_state.bitmap_info.bmiHeader.biSize = sizeof(render_state.bitmap_info.bmiHeader);
            render_state.bitmap_info.bmiHeader.biWidth = render_state.width;
            render_state.bitmap_info.bmiHeader.biHeight = render_state.height;
            render_state.bitmap_info.bmiHeader.biPlanes = 1;
            render_state.bitmap_info.bmiHeader.biBitCount = 32;
            render_state.bitmap_info.bmiHeader.biCompression = BI_RGB;


        } break;

        default : {
            return DefWindowProc(hwnd, msg, wparam, lparam);
        }
    }

    return DefWindowProc(hwnd, msg, wparam, lparam);
}




int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,LPSTR lpCmdLine, int nCmdShow){
    
    InitializeDebuggerConsole();
    using std::cout;
    using std::endl;
    const char class_name[] = "SIMU";

    HWND wnd;
    MSG msg;

    WNDCLASS wc_n = {};

    wc_n.style         = CS_HREDRAW | CS_VREDRAW;
    wc_n.lpfnWndProc   = wnd_simulator;
    wc_n.lpszClassName = class_name;

    if(!RegisterClass(&wc_n)){
        MessageBox(NULL, "Window Registration Failed! wc", "Error!",
            MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }

    wnd = CreateWindow(
        wc_n.lpszClassName,
        "Adventura",
        WS_OVERLAPPEDWINDOW | WS_VISIBLE,
        CW_USEDEFAULT, CW_USEDEFAULT, 980, 480,
        NULL, NULL, GetModuleHandle(NULL), NULL); 

    if(wnd == NULL){
        MessageBox(NULL, "Window Creation Failed! TOOL", "Error!",
        MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }

    ShowWindow(wnd, nCmdShow);
    UpdateWindow(wnd);

    HDC hdc = GetDC(wnd);
    float k = 0.0;

    while(running){
        MSG message;
        
        for(int i = 0; i< BUTTON_COUNT; i++){
            input.buttons[i].changed = false;
        }

        while(PeekMessage(&message, wnd, 0, 0, PM_REMOVE)){
            TranslateMessage(&message);
            DispatchMessage(&message);
        }
        
        /*if(Novas.size() > 0){
            simulate_enemy(Novas);
        }*/

        
        simulate_game(&input, Novas);
        StretchDIBits(hdc, 0, 0, render_state.width, render_state.height, 0, 0, render_state.width, render_state.height, render_state.memory, &render_state.bitmap_info, DIB_RGB_COLORS, SRCCOPY);

        /*
        if(k < 0.25){
            simulate_game(&input,k);
            k = k + 0.001;
        }else{
            simulate_game(&input,k);
        }
        
        
        */
    } 




    return 0;

}
