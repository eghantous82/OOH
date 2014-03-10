import bb.cascades 1.0
Sheet
{
	property bool validEmail: false;
	property bool validExEmail: false;
Page {
	id: pSheet
	
    Container {
    	topPadding: 10
    	bottomPadding: 10
    	leftPadding: 10
    	rightPadding: 10
    	horizontalAlignment: HorizontalAlignment.Fill
    	background: Color.Black
    	Label{
    		text: "Name"
    		textStyle.color: Color.White
    	}
    	TextField
    	{
    		id: name
    		objectName: "name"
    		hintText: "Name"    		
    	}
    	Label
    	{
    		text: "Email"
    		textStyle.color: Color.White
    	}
    	TextField
    	{
    		id: email
    		objectName: "email"
    		hintText: "Email"
    		textStyle.color: validEmail ? Color.Black : Color.Red
    	}
    	Label
    	{
    		text: qsTr("List of emails participant can't get (optional)") + Retranslate.onLanguageChanged
    		textStyle.color: Color.White
    	}
    	Container
    	{
    		Container
    		{
	    		layout: StackLayout
	    		{
	    			orientation: LayoutOrientation.LeftToRight
	    		}
	    		TextField
	    		{
	    			hintText: "Email"
	    			objectName: "exEmail"
	    			textStyle.color: validExEmail ? Color.Black : Color.Red
	    		}
	    		Button
	    		{
	    			maxWidth: 80
	    			text: "+"
	    			objectName: "addExlusion"
	    			enabled: validExEmail
	    		}
    		}// text field and '+' container
    		
    		ListView	// list view of excluded members
    		{
    			objectName: "exList"
    		}
    	}
    	Container
    	{
    		verticalAlignment: VerticalAlignment.Bottom
    		horizontalAlignment: HorizontalAlignment.Center
    		layout: StackLayout
    		{
    			orientation: LayoutOrientation.LeftToRight
    		}
	    	Button
	    	{
	    		objectName: "cancelButton"
				text: "Cancel"	    		
	    	}
	    	Button
	    	{
	    		objectName: "okButton"
	    		text: "OK"
	    		enabled: validEmail && (name.text.length != 0)
	    	}
    	}
    }
}
}