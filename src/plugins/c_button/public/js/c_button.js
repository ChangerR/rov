(function (window, $) {
    'use strict';

    var CButton;

    CButton = function CButton(cockpit) {
        console.log("Loading CButton plugin in the browser.");

        // Instance variables
        this.cockpit = cockpit;
		this.CButton = new Object();
		this.importantCButton = new Object();


        // Add required UI elements
		$("#rov_status_panel").append(
                '<div id="CButton_PAN" class="controller well well-small" > \
					<center>				\
						<div class="btn-group">			  \
						<button class="btn btn-success" id="btn_forward">前</button> \
						<button class="btn btn-success" id="btn_back">后</button> \
						<button class="btn btn-success" id="btn_left">左</button>		\
						<button class="btn btn-success" id="btn_right">右</button> \
						<button class="btn btn-success" id="btn_up">上</button>		\
						<button class="btn btn-success" id="btn_down">下</button> \
						</div> \
					</center> \
					<center style="margin-top:5px;\"> \
						<div class="btn-group">			  \
						<button class="btn btn-success" id="btn_camera_up">摄像头向上</button> \
						<button class="btn btn-success" id="btn_camera_down">摄像头向下</button>\
						</div> \
					</center> \
					<center style="margin-top:5px;"> \
						<button class="btn btn btn-primary" id="btn_camera_back" style="width:40%;">摄像头回复</button>\
						<button class="btn btn-danger" id="btn_stop" style="width:40%;">停止一切</button></button></center> \
				</div>');

		var forward_down = false;
		var back_down = false;
		var left_down = false;
		var right_down = false;
		var up_down = false;
		var down_down = false;
		$("#btn_forward").click(function() {
			var e;
			if(!forward_down) {
				e = jQuery.Event("keydown");
				e.which = 38;
				e.keyCode = 38;
				$(window).trigger(e);
				$("#btn_forward").attr("class","btn btn-danger");
				forward_down = true;
		}else{
			e = jQuery.Event("keyup");
			e.which = 38;
			e.keyCode = 38;
			$(window).trigger(e);
			$("#btn_forward").attr("class","btn btn-success");
			forward_down = false;
		}
	  });
	  
	  $("#btn_back").click(function() {
		var e;
		if(!back_down) {
			e = jQuery.Event("keydown");
			e.which = 40;
			e.keyCode = 40;
			$(window).trigger(e);
			$("#btn_back").attr("class","btn btn-danger");
			back_down = true;
		}else{
			e = jQuery.Event("keyup");
			e.which = 40;
			e.keyCode = 40;
			$(window).trigger(e);
			$("#btn_back").attr("class","btn btn-success");
			back_down = false;
		}
	  });
	  
	  $("#btn_left").click(function() {
		var e;
		if(!left_down) {
			e = jQuery.Event("keydown");
			e.which = 37;
			e.keyCode = 37;
			$(window).trigger(e);
			$("#btn_left").attr("class","btn btn-danger");
			left_down = true;
		}else{
			e = jQuery.Event("keyup");
			e.which = 37;
			e.keyCode = 37;
			$(window).trigger(e);
			$("#btn_left").attr("class","btn btn-success");
			left_down = false;
		}
	  });
	  
	  $("#btn_right").click(function() {
		var e;
		if(!right_down) {
			e = jQuery.Event("keydown");
			e.which = 39;
			e.keyCode = 39;
			$(window).trigger(e);
			$("#btn_right").attr("class","btn btn-danger");
			right_down = true;
		}else{
			e = jQuery.Event("keyup");
			e.which = 39;
			e.keyCode = 39;
			$(window).trigger(e);
			$("#btn_right").attr("class","btn btn-success");
			right_down = false;
		}
	  });
	  
	  $("#btn_up").click(function() {
		var e;
		if(!up_down) {
			e = jQuery.Event("keydown");
			e.which = 16;
			e.keyCode = 16;
			$(window).trigger(e);
			$("#btn_up").attr("class","btn btn-danger");
			up_down = true;
		}else{
			e = jQuery.Event("keyup");
			e.which = 16;
			e.keyCode = 16;
			$(window).trigger(e);
			$("#btn_up").attr("class","btn btn-success");
			up_down = false;
		}
	  });
	  
	  $("#btn_down").click(function() {
		var e;
		if(!down_down) {
			e = jQuery.Event("keydown");
			e.which = 17;
			e.keyCode = 17;
			$(window).trigger(e);
			$("#btn_down").attr("class","btn btn-danger");
			down_down = true;
		}else{
			e = jQuery.Event("keyup");
			e.which = 17;
			e.keyCode = 17;
			$(window).trigger(e);
			$("#btn_down").attr("class","btn btn-success");
			down_down = false;
		}
	  });

	  $("#btn_stop").click(function() {
		var e;
		e = jQuery.Event("keydown");
		e.which = 32;
		e.keyCode = 32;
		$(window).trigger(e);
	  });
	  
	  $("#btn_camera_back").click(function() {
		var e;
		e = jQuery.Event("keydown");
		e.which = 65;
		e.keyCode = 65;
		$(window).trigger(e);
	  });
	  
	  $("#btn_camera_down").click(function() {
		var e;
		e = jQuery.Event("keydown");
		e.which = 90;
		e.keyCode = 90;
		$(window).trigger(e);
	  });
	  
	  $("#btn_camera_up").click(function() {
		var e;
		e = jQuery.Event("keydown");
		e.which = 81;
		e.keyCode = 81;
		$(window).trigger(e);
	  });
    };

	
	  
    window.Cockpit.plugins.push(CButton);

}(window, jQuery));
