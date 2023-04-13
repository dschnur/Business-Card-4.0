// Business Card Joystick Cover
// Dan Schnur
// Tempe Technology
// 9/18/2020

$fn = 80;

difference() {
    hull() {
        linear_extrude(height = 1.75) {
            circle(d=7);
        }
        translate([0,0,.5]) {
            linear_extrude(height = 2) {
            square([4,4],center=true);  
        }
    }
}
    translate([0,0,1]) {
        linear_extrude(height = 4.75) {
            square([2,2],center=true);
        }
    }
}