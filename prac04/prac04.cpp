// prac04.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#include "framework.h"
#include "prac04.h"

#include <Windows.h>
#include "global.h"
#include "input_manager.h"
#include "texture_manager.h"

#define MAX_LOADSTRING 100

// 전역 변수:
HINSTANCE hInst;                              
WCHAR szTitle[MAX_LOADSTRING];              
WCHAR szWindowClass[MAX_LOADSTRING];          

// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);

LPDIRECT3D9             g_pD3D = NULL; 
LPDIRECT3DDEVICE9       g_pd3dDevice = NULL; 
//LPDIRECT3DTEXTURE9      g_pTexture = NULL;
//ID3DXSprite* g_pSprite = NULL;

TextureManager textureManager;
InputManager inputManager;
StageManager stageManager;

int spriteX = 0;
int spriteY = 0;

HRESULT InitD3D(HWND hWnd)
{
    if (NULL == (g_pD3D = Direct3DCreate9(D3D_SDK_VERSION)))
        return E_FAIL;

    D3DPRESENT_PARAMETERS d3dpp;
    ZeroMemory(&d3dpp, sizeof(d3dpp));

   d3dpp.Windowed = TRUE;
    //d3dpp.Windowed = false;

    d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;

   d3dpp.BackBufferWidth = WINDOW_WIDTH;
   d3dpp.BackBufferHeight = WINDOW_HEIGHT;
   d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;
   //d3dpp.BackBufferFormat = D3DFMT_A8B8G8R8;

    d3dpp.EnableAutoDepthStencil = TRUE;
    d3dpp.AutoDepthStencilFormat = D3DFMT_D16;

    if (FAILED(g_pD3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd,
        D3DCREATE_SOFTWARE_VERTEXPROCESSING,
        &d3dpp, &g_pd3dDevice)))
    {
        return E_FAIL;
    }

    g_pd3dDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);
    g_pd3dDevice->SetRenderState(D3DRS_LIGHTING, FALSE);
    g_pd3dDevice->SetRenderState(D3DRS_ZENABLE, TRUE);

    return S_OK;
}
void EngineUpdate() {
    if (inputManager.keyBuffer[VK_LEFT]==1) {
        spriteX -= 1;
    }
    if (inputManager.keyBuffer[VK_RIGHT] == 1) {
        spriteX += 1;
    }
    if (inputManager.keyBuffer[VK_UP] == 1) {
        spriteY -= 1;
    }
    if (inputManager.keyBuffer[VK_DOWN] == 1) {
        spriteY += 1;
    }

    inputManager.Update();
    stageManager.Update();
}

VOID EngineRender()
{
    g_pd3dDevice->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER,
        D3DCOLOR_XRGB(0, 0, 255), 1.0f, 0);

    if (SUCCEEDED(g_pd3dDevice->BeginScene()))
    {      
        stageManager.Render();
        /*TextureElement* element = textureManager.GetTexture(1);

        element->Sprite->Begin(D3DXSPRITE_ALPHABLEND);

        RECT rect;
        rect.top = 0;
        rect.left = 0;
        rect.bottom = 64;
        rect.right = 64;

        D3DXVECTOR3 pos(spriteX, spriteY, 0);
        
        element->Sprite->Draw(element->Texture, &rect, nullptr, &pos, D3DCOLOR_XRGB(255, 255, 255));
        element->Sprite->End();*/

        g_pd3dDevice->EndScene();
    }
    g_pd3dDevice->Present(NULL, NULL, NULL, NULL);
}
void InitMyStuff() {
    textureManager.LoadTexture(L"banana.png", 1);
    textureManager.LoadTexture(L"green.png", TEX_TITLE_SCREEN);

    stageManager.MakeTitleScreen();
}

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // 전역 문자열을 초기화합니다.
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_PRAC04, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 애플리케이션 초기화를 수행합니다:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_PRAC04));

    MSG msg;
    ZeroMemory(&msg, sizeof(msg));
    while (msg.message != WM_QUIT)
    {
        if (PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        else {
            EngineUpdate();
            EngineRender();
        }
    }
    return (int) msg.wParam;
}

ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_PRAC04));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName = nullptr;//MAKEINTRESOURCEW(IDC_PRAC04);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT,0, WINDOW_WIDTH, WINDOW_HEIGHT, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   InitD3D(hWnd);
   InitMyStuff();
   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_LBUTTONDOWN:
        inputManager.keyBuffer[VK_LBUTTON]=1;
        break;
    case WM_LBUTTONUP:
        inputManager.keyBuffer[VK_LBUTTON] = 0;
        break;
    case WM_RBUTTONDOWN:
        inputManager.keyBuffer[VK_RBUTTON] = 1;
        break;
    case WM_RBUTTONUP:
        inputManager.keyBuffer[VK_RBUTTON] = 0;
        break;
    case WM_KEYDOWN:
        inputManager.keyBuffer[wParam] = 1;
        break;
    case WM_KEYUP:
        inputManager.keyBuffer[wParam] = 0;
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}