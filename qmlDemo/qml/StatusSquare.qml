import QtQuick

Rectangle 
{
    id: base
    width: 60
    height: 60
    radius: 6
    color: base.status ? "lawngreen" : "gray"
    
    property string label: "UND"
    property bool status: false
    
    Rectangle 
    {
        anchors.fill: parent
        anchors.topMargin: 2
        anchors.bottomMargin: 2
        anchors.leftMargin: 2
        anchors.rightMargin: 2
        border.color: "black"
        border.width: 2
        radius: 8
        color: "transparent"
    }

    Text
    {
        anchors.centerIn: parent
        text: base.label
    }
}
