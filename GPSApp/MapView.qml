import QtQuick 2.0
import QtLocation 5.6
import QtQuick.Controls 2.0
import QtPositioning 5.2

Item {
    id: item

    function start() {
        mapItem.clearMapItems();
        mapItem.track = Qt.createQmlObject('import QtLocation 5.6; MapPolyline {}', item);
        mapItem.track.line.width = 6;
        mapItem.track.line.color = 'red';
        mapItem.addMapItem(mapItem.track);

    }

    function appendCoordinate(position){
        mapItem.center = position;
        mapItem.track.addCoordinate(position)
    }




    Map {
        id: mapItem

        plugin: mapPlugin
        zoomLevel: 16

        width: item.width
        height:item.height

        property MapPolyline track
    }


    PositionSource {


            onPositionChanged: {

                // center the map on the current position
                console.log(position.coordinate)
                mapItem.center = position.coordinate



            }

        }



    Connections {
        target: ASD
        onTransmitNewText: text1.text = req
    }

    Text {
        id: text1
        text: index
        //text: qsTr(Position.latitudeValid())
        //anchors.centerIn: parent
    }

    MouseArea {
        anchors.fill: parent
        onPressAndHold:{
            var current =  gpsSrc.position.coordinate;
            var distance = mapItem.toCoordinate(Qt.point(mouse.x,mouse.y))
            ASD.sendData(current.latitude, current.longitude, text1.text)
        }
    }



        /*PositionSource {
            id: gpsSrc
            updateInterval: 5000
            preferredPositioningMethods: PositionSource.SatellitePositioningMethods


            onPositionChanged: {
                console.log(ASD.getOldText(text1.text))
            }*/


    Timer {
        interval: 100; running: true; repeat: false
        onTriggered: {
            for(var i = 0;
                i < mapItem.supportedMapTypes.length;
                ++i){
                if(mapItem.supportedMapTypes[i].style
                        === MapType.CustomMap){
                    mapItem.activeMapType = mapItem.supportedMapTypes[i];
                }
            }
        }
    }

    Button{
        anchors{
            right: parent.right
            top:parent.top
            margins: 20
        }

        background:Rectangle{

            anchors.centerIn: parent
            implicitWidth:icon.width
            implicitHeight: icon.height

            radius: 5

            color:"white"
                Image{
                    id: icon
                    anchors.centerIn: parent
                    source: "qrc:/images/resize.png"
            }
        }

        onClicked: {
            item.state = item.state === "full" ? "normal" : "full";
        }
    }

    states:[
        State {
            name: "normal"

            PropertyChanges{
                target: mapItem
                height: item.height
                width: item.width
            }
        },
        State{
            name: "full"
            PropertyChanges{
                target: mapItem
                height: app.height
                width: app.width
            }
        }

    ]

    state: "nornal"


}
