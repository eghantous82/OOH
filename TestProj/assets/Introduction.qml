import bb.cascades 1.0

NavigationPane {
    id: navigationPane
    attachedObjects: [
        ComponentDefinition {
            id: appCover
            source: "SceneCover.qml"
        }
    ]
    onCreationCompleted: {
	    Application.cover = appCover.createObject();
	}
    Page {
        titleBar: TitleBar {
            title: "Introduction"
        }

        ScrollView {
        	scrollViewProperties {
        		scrollMode: ScrollMode.None
    		}
    		Container{
        	background: Color.Black
        	horizontalAlignment: HorizontalAlignment.Fill
        	verticalAlignment: VerticalAlignment.Fill
        	
        	layout:  DockLayout{}
        	Container
        	{
        		verticalAlignment: VerticalAlignment.Center
        		horizontalAlignment: HorizontalAlignment.Center
	        	Label
	        	{
	        		text: "Hi There!  This app can be used to organize a picking out of a hat scenario.  The app is setup not to allow anyone to get their own name, and optionally not allow certain pairings of your choosing.  There are a few simple steps needed begin:"
	        		multiline: true
	        		textStyle.color: Color.White
	        	}
	        	Label
	        	{
	        		text: "1. Setup an email message that will be emailed to the participants\n2. Enter in participant information (don't forget yourself!)\n3. Send the emails!"
	        		multiline: true
	        		textStyle.color: Color.White	
	        	}
	        	Label
	        	{
	        		text: "Note:  The emails will be sent using the personal email account configured on this device.  The emails will be available in the \"Sent Items\".  No peeking!!!"
	        		multiline: true
	        		textStyle.color: Color.White	
	        	}
        	}
        	}
        }

        actions: ActionItem {
            title: qsTr("Start")
            ActionBar.placement: ActionBarPlacement.OnBar
			imageSource: "asset:///start.png"
			objectName: "setupEmail"
        }
    }
  
}
