import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.3

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("QVariantList and QVariant Map")

    // the function should be on root object

    function arrayObjectFunc(array, object) {
        console.log("---Printing array---")
        array.forEach(function (el) {
            console.log("Array Element:", el)
        })

        console.log("---Printing object---")
        for(var mKey in object) {
            console.log(`Object[${mKey}]:${object[mKey]}`)
        }
    }

    Button {
        id: button1
        text: "Pass data to Cpp"
        onClicked: {
            var arr = ['Africa', 'Asia', 'Europe', 'North America', 'South America', 'Oceania']
            var obj = {
                firstName: "John",
                lastName: "Doe",
                location: "Earth"
            }
            CppClass.passFromQmlToCpp(arr, obj);
        }
    }

    Button {
        id: button2
        anchors.top: button1.bottom
        text: "Get Variant List from Cpp"
        onClicked: {
            var data = CppClass.getVariantListFromCpp() // return array
            data.forEach(function(element) {
                console.log("Array item:", element);
            });
        }
    }

    Button {
        id: button3
        anchors.top: button2.bottom
        text: "Get Variant Map from Cpp"
        onClicked: {
            var data = CppClass.getVariantMapFromCpp() // return object
            for (var mKey in data){
                console.log(`Object[${mKey}]: ${data[mKey]}`);
            }
        }
    }

    Button {
        id: button4
        anchors.top: button3.bottom
        text: "Trigger Js Call"
        onClicked: {
            CppClass.triggerJsCall();
        }
    }

}
