import bb.cascades 1.0
 
SceneCover {
    // The content property must be explicitly specified
    content: Container {
    	horizontalAlignment: HorizontalAlignment.Fill
        verticalAlignment: VerticalAlignment.Fill
        Container {
            layout: DockLayout {
            }
            background: Color.Black
            ImageView {
                imageSource: "asset:///icon_big.png"
                scalingMethod: ScalingMethod.Fill
            }
        }
    }
}