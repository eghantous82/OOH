import bb.cascades 1.0

Page {
    titleBar: TitleBar {
        title: "Email Message"
        dismissAction: ActionItem {
            objectName: "cancelAction"
            title: "Cancel"
        }
        
        acceptAction: ActionItem {
            objectName: "doneAction"
            title: "Done"
        }
        
    }
    Container {
    	background: Color.Black
    	Label
    	{
    		text: "Enter the subject of the email to be sent"
    		textStyle.color: Color.White
    	}
    	TextField
    	{
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
    		objectName: "emailBody"
    		hintText: "Enter Body"
			layoutProperties: StackLayoutProperties 
			{
				spaceQuota: 1
			}
			bottomPadding: 10
    	}
    }
}
