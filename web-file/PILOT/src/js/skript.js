

function save(name, val)
{


$.ajax({
        method: "POST",
        url: "udpate.php",
        data: { opt: name, value_opt: val }
      })
        .done(function( ) {
          
        });
}

function colo(id)
{
        var h=$("#"+id).val();

       
                let r = 0, g = 0, b = 0;
              
                // 3 digits
                if (h.length == 4) {
                  r = "0x" + h[1] + h[1];
                  g = "0x" + h[2] + h[2];
                  b = "0x" + h[3] + h[3];
              
                // 6 digits
                } else if (h.length == 7) {
                  r = "0x" + h[1] + h[2];
                  g = "0x" + h[3] + h[4];
                  b = "0x" + h[5] + h[6];
                }
                
                r=parseInt(r);
                g=parseInt(g);
                b=parseInt(b);
                save('red',r);
                save('green',g);
                save('blue',b);
                
              
}       