"use strict";

// GenericViewer just displays message fields and values in a table.
// It can be used on any ROS type.

class JoystickController extends Viewer {
  /**
    * Gets called when Viewer is first initialized.
    * @override
  **/
  onCreate() {
    this.viewerNode = $('<div id="zone_joystick" style="position: relative;"></div>')
      .css({'font-size': '11pt'})
      .appendTo(this.card.content);

    this.viewerNodeFadeTimeout = null;

    this.expandFields = { };
    this.fieldNodes = { };
    
    super.onCreate();
  }
  
}

JoystickController.friendlyName = "Joystick";

JoystickController.supportedTypes = [
  "joystick",
];

Viewer.registerViewer(JoystickController);