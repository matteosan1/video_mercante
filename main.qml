import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0
import QtMultimedia 5.5
import QtQuick.Window 2.2 // Window.FullScreen

ApplicationWindow {
    visible: true
    //width: 800
    //height: 600
    title: qsTr("MERCANTE IN FIERA (VIDEO)")
    id: mainWindow
    visibility: Window.FullScreen
    property bool firstTime: true


    Rectangle {
        anchors.fill: parent
        color: "black"

        Connections {
            target: films
            onAppQuit: {
                Qt.quit()
            }
        }

        Image {
            id: cinema_muto
            anchors.fill: parent
            source: "file:///Users/sani/video_mercante/cinema_muto_1.jpg"
            visible: false
        }

        Text {
            anchors.horizontalCenter: cinema_muto.horizontalCenter
            anchors.top: cinema_muto.top
            anchors.topMargin: parent.height / 10.
            id: titolo
            color: "#bec7c7"
            font.pixelSize: 60
            //textFormat: Text.StyledText
            font.family: "Market Deco"
            text: qsTr(films.titolo)
            visible: false
        }

        Text {
            anchors.horizontalCenter: cinema_muto.horizontalCenter
            anchors.top: titolo.bottom
            anchors.topMargin: 40
            width: cinema_muto.width-300
            height: cinema_muto.height
            id: domanda
            color: "#bec7c7"
            wrapMode: Text.WordWrap
            font.pixelSize: 36
            //textFormat: Text.StyledText
            font.family: "Market Deco"
            text: qsTr(films.domanda)
            visible: false
        }

        Video {
            id: video
            anchors.fill: parent
            fillMode : VideoOutput.PreserveAspectFit
            source: films.fileSource
            anchors.centerIn: parent

            focus: true
            Keys.onSpacePressed: {
                if (video.playbackState == MediaPlayer.PlayingState) {
                    video.pause();
                }
                else {
                    if (mainWindow.firstTime) {
                        films.changeFilm()
                        titolo.visible = false
                        domanda.visible = false
                        cinema_muto.visible=false
                        video.play()
                        mainWindow.firstTime = false
                    }
                }
            }
            //Keys.onLeftPressed: video.seek(video.position - 5000)
            //Keys.onRightPressed: video.seek(video.position + 5000)

            onStopped: {
                if (mainWindow.firstTime) {
                    mainWindow.firstTime = false
                    video.play()
                }
                else {
                    titolo.visible = true
                    domanda.visible = true
                    cinema_muto.visible = true
                    mainWindow.firstTime = true
                }
            }
        }
    }
}
