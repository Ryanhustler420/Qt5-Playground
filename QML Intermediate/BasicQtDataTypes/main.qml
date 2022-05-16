import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.5

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Data Conversion : Basic Types")


    Connections {
        target: CppClass

        onSendInt : {
            console.log("Received int :" + param + " , type is :" + typeof param)
        }

        onSendDouble : {
            console.log("Received double :" + doubleParam + " , type is :" + typeof doubleParam)
        }

        onSendBoolRealFloat:{
            //bool boolparam, real realparam, float floatparam
            console.log("Received bool :" + boolparam + " , type is :" + typeof boolparam)
            console.log("Received real :" + realparam + " , type is :" + typeof realparam)
            console.log("Received float :" + floatparam + " , type is :" + typeof floatparam)
        }

        onSendStringUrl:{
            console.log("Received string :" + stringparam + " , type is :" + typeof stringparam)
            console.log("Received url :" + urlparam + " , type is :" + typeof urlparam)
        }

        onSendColorFont:{
            console.log("Received color :" + colorparam + " , type is :" + typeof colorparam)
            console.log("Received font :" + fontparam + " , type is :" + typeof fontparam.family)

            //Access properties of object
            console.log("Color components : red : " + colorparam.r + " , green :" + colorparam.g + ", blue :"+  colorparam.b);
            console.log("Font family : " + fontparam.family)
            console.log("Font bold : " + fontparam.bold)

            mRect.color = colorparam
            mButton.font = fontparam
        }

        onSendDate:{
            console.log("Received date :" + dateparam + " , type is :" + typeof dateparam)
            //Extract info
            console.log("Year is :" + dateparam.getFullYear())
            console.log("Month is :" + dateparam.getUTCMonth())
            console.log("Day of week is :" + dateparam.getDay())
            console.log("The day of moth is :" + dateparam.getDate())
        }

        onSendPoint:{
            console.log("Received point :" + pointparam + " , type is :" + typeof pointparam)
            console.log("Received pointf :" + pointfparam + " , type is :" + typeof pointfparam)

            //Extract info
            console.log("point.x : " + pointparam.x + "\npoint.y : "+ pointparam.y +
                        "\npointf.x :"+ pointfparam.x + "\npointf.y :"+ pointfparam.y)
        }

        onSendSize:{
            console.log("Received size :" + sizeparam + " , type is :" + typeof sizeparam)
            console.log("Received sizef :" + sizefparam + " , type is :" + typeof sizefparam)

            //Extract info
            console.log("size.width : " + sizeparam.width + "\nsize.height : "+ sizeparam.height +
                        "\nsizef.witdth :"+ sizefparam.width + "\nsizef.height :"+ sizefparam.height)
        }
        onSendRect:{
            console.log("Received rect :" + rectparam + " , type is :" + typeof rectparam)
            console.log("Received rectf :" + rectfparam + " , type is :" + typeof rectfparam)

            //Extract ifno
            console.log("rect.x : " + rectparam.x + "\nrect.y : "+ rectparam.y +
                        "\nrect.width : " + rectparam.width + "\nrect.height : "+ rectparam.height )

            console.log("\n\n\nrectf.x : " + rectfparam.x + "\nrectf.y : "+ rectfparam.y +
                        "\nrectf.width : " + rectfparam.width + "\nrectf.height : "+ rectfparam.height )

        }


    }

    Rectangle{
        id : mRect
        width: 200
        height: 200
        color: "black"
        radius: 20
    }

    Button{
        id : mButton
        anchors.top: mRect.bottom
        text : "Click Me"
        onClicked: {
            //CppClass.cppSlot()
            //CppClass.receivePoint(Qt.point(200,300))
            CppClass.receiveRect(Qt.rect(40.10,40,100,100))
        }
    }
}
