import QtQuick
import QtQuick.Controls

ApplicationWindow
{
    visible: true
    width: kb.width
    height: kb.height
    KeyboardStatus
    {
        id: kb
    }
    
    function getKB()
    {
        kb.testCall();
    }
}
