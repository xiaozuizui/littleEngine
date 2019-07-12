
from ctypes import*

RenderDLL = 'RenderDLL.dll'
dll = None

def InitDLL():
    global dll 
    dll = CDLL(RenderDLL)
    pass

def SetHwnd(QWidget):
    global dll 
    hand = int(QWidget.winId());
    print(hand,'Set to RenderTarget')
    dll.InitModelViewer(hand,10,10)

def LoadObj(name):
    global dll 
    Name_p = c_char_p(name.encode())
 
    print(Name_p.value,'loading')
#pVoid = ctypes.cast( pStr, ctypes.c_void_p ).value  
    isload = dll.LoadObj(Name_p)
    return isload
   
   
    