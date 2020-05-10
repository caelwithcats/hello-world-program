#include <stdio.h>
#include <windows.h>
long FAR PASCAL __export WndProc(HWND, UINT, UINT, LONG);

int PASCAL WinMain(HANDLE hInstance, HANDLE hPrevInstance, LPSTR lpszCmdParam, int nCmdShow){
	static char szAppName[] = "helloWin";
	HWND hwnd;
	MSG msg;
	WNDCLASS wndclass;

	if(!hPrevInstance){
		wndclass.style = CS_HREDRAW | CS_VREDRAW;
		wndclass.lpfnWndProc = WndProc;
		wndclass.cbClsExtra = 0;
		wndclass.cbWndExtra = 0;
		wndclass.hInstance = hInstance;
		wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
		wndclass.hCursor = LoadCursor(NULL,IDC_ARROW);
		wndclass.hbrBackground = GetStockObject(WHITE_BRUSH);
		wndclass.lpszMenuName = NULL;
		wndclass.lpszClassName = szAppName;

                RegisterClass(&wndclass);
	}
	hwnd = CreateWindow(szAppName,"HELLO WORLD!", WS_OVERLAPPEDWINDOW,CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,CW_USEDEFAULT,NULL,NULL,hInstance, NULL);
	ShowWindow(hwnd,nCmdShow);
	UpdateWindow(hwnd);
	while(GetMessage(&msg,NULL,0,0)){
		TranslateMessage(&msg);
                DispatchMessage(&msg);
	}
	return msg.wParam;
}
long FAR PASCAL _export WndProc(HWND hwnd, UINT message, UINT wParam, LONG lParam){

	HDC hdc;
	PAINTSTRUCT ps;
	RECT rect;

	switch(message){
		case WM_PAINT:
			hdc = BeginPaint(hwnd,&ps);

			GetClientRect(hwnd, &rect);

			DrawText(hdc, "hello world!", -1, &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
			EndPaint(hwnd,&ps);
			return 0;
		case WM_DESTROY:
			PostQuitMessage(0);
                        return 0;
        }
        return DefWindowProc(hwnd,message,wParam,lParam);
}
int main()
{
 printf("hello world!\n");
 return 0;     
}