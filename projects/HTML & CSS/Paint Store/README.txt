This project mainly focuses on color manipulation using CSS
We have four ways of representing colors in CSS

Using the normal color naming
      color: black;
      
Using RGB() values, RGB stands for Red, Green, Blue. Each value take a number between 0 - 255. The values represent the intensity of the colors
      color: rgb(0, 0, 0); - This will show black
      color: rgb(255, 255, 255); - This will show white

Using HSL() values, HSL stands for hue, saturation, lighting. Hue takes a value from 0 to 360. Saturation and lighting takes percentage from 0% - 100%
      color: hsl(11, 100%, 0%); - This will show black
      color: hsl(11, 0%, 100%); - This will show white

Using HEX. HEX is a 6 char code consisting of numbers and characters used to represent colors
      color: #000000; - Black
      color: #ffffff; - White

The project also involves opacity. Opacity can be simply put as how transparent or opaque a color is.
      opacity: 0; - Fully transaparent
      opacity: 1; - Fully opaque

You can present colors including also the opacity. In this case its called the alpha and represented by a
The alpha can be used in RGB() makeing it RGBA() or HSL making it HSLA()
      color: rgba(255, 255, 255, 0.9) - Almost opaque white
      color: hsla(11, 0%, 100%, 0.1) - Almost transparent white
