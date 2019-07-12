import sys
from PyQt5.QtWidgets import QWidget,QApplication
from ctypes import*

from RenderModule import*


class ModelViewer(QWidget):
    def __init__(self, *args, **kwargs):

        return super().__init__(*args, **kwargs)

    def LoadObj(self,name):
        pStr = c_char_p( )  
        pStr.value = name  
#pVoid = ctypes.cast( pStr, ctypes.c_void_p ).value  
        dll.PrintInfo(pStr, len(pStr.value))  
          

if __name__ == '__main__':

    import os
    print(os.getcwd())
   
    app = QApplication(sys.argv)
    test = QWidget()
    test.resize(400,400)
    
    test.setWindowTitle('test')
    test.show()
   

    
    InitDLL()
    isload=LoadObj('issue-177.obj')

    sys.exit(app.exec_())