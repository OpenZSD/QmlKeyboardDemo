import QtQuick
import QtQuick.Layouts
import StatusKey 1.0

Rectangle 
{
    id: base
    visible: true
    color: "transparent"
    width: widestRow.width
    height: cl.height
    
    ColumnLayout
    {
        id: cl
        Layout.alignment: Qt.AlignHCenter
        RowLayout
        {
            id: widestRow
            Layout.alignment: Qt.AlignHCenter
            Repeater
            {
                model: ['`','1','2','3','4','5','6','7','8','9','0','-','=']
                StatusSquare
                {
                    StatusKey
                    {
                        id: firstRowStatus
                        key: modelData
                    }
                    id: firstRowKey
                    property string key: modelData
                    label: modelData
                    status: firstRowStatus.status
                }
            }
        }
        RowLayout
        {
            Layout.alignment: Qt.AlignHCenter
            Repeater
            {
                model: ['q','w','e','r','t','y','u','i','o','p','[',']','\\']

                StatusSquare
                {
                    StatusKey
                    {
                        id: secondRowStatus
                        key: modelData
                    }
                    id: secondRowKey
                    property string key: modelData
                    label: modelData.toUpperCase()
                    status: secondRowStatus.status
                }
            }
        }
        RowLayout
        {
            Layout.alignment: Qt.AlignHCenter
            Repeater
            {
                model: ['a','s','d','f','g','h','j','k','l',';','\'']
                StatusSquare
                {
                    StatusKey
                    {
                        id: thirdRowStatus
                        key: modelData
                    }
                    id: thirdRowKey
                    property string key: modelData
                    label: modelData.toUpperCase()
                    status: thirdRowStatus.status
                }
            }
        }
        RowLayout
        {
            Layout.alignment: Qt.AlignHCenter
            Repeater
            {
                model: ['z','x','c','v','b','n','m',',','.','/']

                StatusSquare
                {
                    StatusKey
                    {
                        id: fourthRowStatus
                        key: modelData
                    }
                
                    id: fourthRowKey
                    property string key: modelData
                    label: modelData.toUpperCase()
                    status: fourthRowStatus.status
                }
            }
        }
        StatusSquare
        {
            StatusKey
            {
                id: fifthRowStatus
                key: ' '
            }
            id: fifthRowKey
            Layout.alignment: Qt.AlignHCenter
            label: "SPACE"
            property string key: ' '
            width: 200
            status: fifthRowStatus.status
        }
    }
}
