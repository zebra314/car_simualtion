import { local_ip } from './local_ip.js';
import './roslib.js';
import './nipplejs.js';

// Connection
var ros = new ROSLIB.Ros({
  // Change to robot ip address 
  // 9090 is the default port of rosbridge server
  url: 'ws://' + local_ip + ':9090'
});

ros.on('connection', function () {
  document.getElementById("status").innerHTML = "Connected";
});

ros.on('error', function (error) {
  document.getElementById("status").innerHTML = "Error";
});

ros.on('close', function () {
  document.getElementById("status").innerHTML = "Closed";
});

var txt_listener = new ROSLIB.Topic({
  ros: ros,
  name: '/txt_msg',
  messageType: 'std_msgs/String'
});

txt_listener.subscribe(function (m) {
  document.getElementById("msg").innerHTML = m.data;
  move(1, 0);
});

// Joystick control
var cmd_vel_listener = new ROSLIB.Topic({
  ros: ros,
  name: "/pollo/cmd_vel",
  messageType: 'geometry_msgs/Twist'
});

var linear_speed = 0;
var angular_speed = 0;

function move(linear, angular) {
  var twist = new ROSLIB.Message({
    linear: {
      x: linear,
      y: 0,
      z: 0
    },
    angular: {
      x: 0,
      y: 0,
      z: angular
    }
  });
  cmd_vel_listener.publish(twist);
}

function createJoystick() {
  var options = {
    zone: document.getElementById('zone_joystick'),
    threshold: 0.1,
    position: { left: 50 + '%' },
    mode: 'static',
    size: 150,
    color: '#000000',
  };
  var manager = nipplejs.create(options);

  var timer = null;
  manager.on('start', function (event, nipple) {
    timer = setInterval(function () {
      move(linear_speed, angular_speed);
    }, 25);
  });

  manager.on('move', function (event, nipple) {
    var max_linear = 1.7; // m/s
    var max_angular = 1.3; // rad/s
    var max_distance = 75.0; // pixels;
    linear_speed = Math.sin(nipple.angle.radian) * max_linear * nipple.distance / max_distance;
    angular_speed = -Math.cos(nipple.angle.radian) * max_angular * nipple.distance / max_distance;
  });

  manager.on('end', function () {
    if (timer) {
      clearInterval(timer);
    }
    move(0, 0);
  });
}

// Slider Control
// Function to initialize slider control
function initSliderControl() {
  // Replace the following lines with your actual slider control initialization code
  // Example: Initialize four slider controls with different IDs

  const slider1 = document.getElementById('slider1'); // Replace with the actual ID of the first slider element
  const slider2 = document.getElementById('slider2'); // Replace with the actual ID of the second slider element
  const slider3 = document.getElementById('slider3'); // Replace with the actual ID of the third slider element
  const slider4 = document.getElementById('slider4'); // Replace with the actual ID of the fourth slider element

  // Customize the appearance and behavior of each slider as needed
  // Example: You can use input[type="range"] elements for sliders
  // and set their min, max, step, and initial values
  slider1.type = 'range';
  slider1.min = '-1';
  slider1.max = '1';
  slider1.step = '0.01';
  slider1.value = '0';

  slider2.type = 'range';
  slider2.min = '-1';
  slider2.max = '1';
  slider2.step = '0.01';
  slider2.value = '0';

  slider3.type = 'range';
  slider3.min = '-1';
  slider3.max = '1';
  slider3.step = '0.01';
  slider3.value = '0';

  slider4.type = 'range';
  slider4.min = '-1';
  slider4.max = '1';
  slider4.step = '0.01';
  slider4.value = '0';

  // Add event listeners to respond to changes in slider values
  // Example: You can listen for the 'input' event on each slider to detect value changes
  slider1.addEventListener('input', function () {
    // Handle value change for the first slider
    // You can publish the value to ROS or perform other actions here
  });

  slider2.addEventListener('input', function () {
    // Handle value change for the second slider
    // You can publish the value to ROS or perform other actions here
  });

  slider3.addEventListener('input', function () {
    // Handle value change for the third slider
    // You can publish the value to ROS or perform other actions here
  });

  slider4.addEventListener('input', function () {
    // Handle value change for the fourth slider
    // You can publish the value to ROS or perform other actions here
  });

  // Add further customization or event listeners as needed
}

// Switch Page
function initPage() {
  createJoystick();
  initSliderControl();
  switchPage('joystickPage');
}
window.addEventListener('load', initPage);

function switchPage(pageId) {
  document.getElementById('joystickPage').style.display = 'none';
  document.getElementById('sliderPage').style.display = 'none';
  document.getElementById(pageId).style.display = 'block';
}

const joystickPage_btn = document.getElementById("joystickPage_btn");
joystickPage_btn.addEventListener("click", function () {
  console.log('joystickPage_btn');
  switchPage('sliderPage');
});

const sliderPage_btn = document.getElementById("sliderPage_btn");
sliderPage_btn.addEventListener("click", function () {
  console.log('sliderPage_btn');
  switchPage('joystickPage');
});



