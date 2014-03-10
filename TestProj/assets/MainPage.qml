import bb.cascades 1.0
Sheet
{
	id: sheet
	property bool workInProgress: false
	property bool allDone: false
	property int numParticipants: 0
Page {
    titleBar: TitleBar {
	    kind: TitleBarKind.Segmented
	    id: titleBar
	    options: [
	        Option {
	            text: "Email"
	            value: "Email"
	        },
	        Option {
	            text: "Participants"
	            value: "Participants"	            
	        }
	    ]
    }
    actions: [
    		ActionItem {
                objectName: "backAction"
                imageSource: "asset:///back.png"
                ActionBar.placement: ActionBarPlacement.OnBar
                title: "Back"
                onTriggered:
                {
                	sheet.close();
                }
                enabled: !workInProgress
            },
            ActionItem {
                objectName: "sendAction"
                imageSource: "asset:///envelope.png"
                ActionBar.placement: ActionBarPlacement.OnBar
                title: "Send!"
                enabled: emailSubject.text.length != 0 && emailBody.text.length != 0 && numParticipants > 1 && !allDone && !workInProgress
            },
            ActionItem {
                objectName: "clearAction"
                imageSource: "asset:///clear_all.png"
                ActionBar.placement: ActionBarPlacement.OnBar
                title: "Clear All"
                enabled: !workInProgress
            }
        ]
    content:
    
    Container{
    // container for email
    Container {
    	visible: (titleBar.selectedOption.value == "Email") && !workInProgress && !allDone
    	background: Color.Black
    	topPadding: 10
    	bottomPadding:10
    	Label
    	{
    		text: "Enter the subject of the email to be sent"
    		textStyle.color: Color.White
    	}
    	TextField
    	{
    		id: emailSubject
    		objectName: "emailSubject"
    		hintText: "Enter Subject"
    	}
    	Label
    	{
    		text: "Enter the body of the email message"
    		textStyle.color: Color.White
    	}
    	TextArea
    	{
    		id: emailBody
    		objectName: "emailBody"
    		hintText: "Enter Body"
			layoutProperties: StackLayoutProperties 
			{
				spaceQuota: 1
			}
    	}
    }// End container for email
    
    //************************** Container for participants *************
    Container
    {
    	topPadding: 10
    	background: Color.Black
    	visible: (titleBar.selectedOption.value == "Participants") && !workInProgress && !allDone
    	
    	Button
    	{
    		horizontalAlignment: HorizontalAlignment.Center
    		objectName: "addParticipant"
    		text: "Add Participant"

    	}
    	ListView
    	{
    		id: listView
    		objectName: "listView"
    	}
    	
    }// End container for participants
    
    //************************** Container for participants *************
    Container
    {
    	visible: workInProgress || allDone
    	background: Color.Black
    	horizontalAlignment: HorizontalAlignment.Fill
    	verticalAlignment: VerticalAlignment.Fill
    	layoutProperties : StackLayoutProperties
    	{
    		spaceQuota: 1
    	}
    	layout: DockLayout{}
    	Container
    	{
	    	background: Color.Black
	    	horizontalAlignment: HorizontalAlignment.Center
	    	verticalAlignment: VerticalAlignment.Center
	    	
	    	Label
	    	{
	    	visible: workInProgress
	    	horizontalAlignment: HorizontalAlignment.Center
	    	verticalAlignment: VerticalAlignment.Center
	    		text: "Performing selection and sending emails!"
	    		textStyle.color:  Color.White
	    	}
	    	Button
	    	{
	    	visible: workInProgress
	    	horizontalAlignment: HorizontalAlignment.Center
	    	verticalAlignment: VerticalAlignment.Center
	    		text: "Cancel"
	    		objectName: "cancelWork"
	    	}
	    	ImageView
	    	{
	    	horizontalAlignment: HorizontalAlignment.Center
	    	verticalAlignment: VerticalAlignment.Center
	    		visible: allDone
	    		imageSource: "asset:///all_done.png"
	    	}
	    	Label
	    	{
	    	horizontalAlignment: HorizontalAlignment.Center
	    	verticalAlignment: VerticalAlignment.Center
	    		visible: allDone
	    		text: "Congrats!  All emails have been sent!"
	    		textStyle.color: Color.White
	    	}
	    	Button
	    	{
	    	horizontalAlignment: HorizontalAlignment.Center
	    	verticalAlignment: VerticalAlignment.Center
	    		visible: allDone
	    		text: "Close"
	    		objectName: "closeButton"
	    	}
    	}
    }// end Cancel Container
    }// content container
}
}