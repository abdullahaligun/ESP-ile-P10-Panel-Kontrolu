const char MAIN_page[] PROGMEM = R"=====(<!doctype html>
<html class="no-js" lang="">

<head>
  <meta charset="utf-8">
  <title></title>
  <meta name="description" content="">
  <!-- Place favicon.ico in the root directory -->


  <meta name="theme-color" content="#fafafa">
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <style>
    html {
      font-family: Arial;
      display: inline-block;
      margin: 0px auto;
      text-align: center;
    }

    h1 { font-size: 2.0rem; color:#2980b9;}

    .buttonSend {
      display: inline-block;
      padding: 10px 25px;
      font-size: 16px;
      font-weight: bold;
      cursor: pointer;
      text-align: center;
      text-decoration: none;
      outline: none;
      color: #ffffff;
      background-color: #4CAF50;
      border: none;
      border-radius: 15px;
      box-shadow: 0 5px #999;
    }
    .buttonSend:hover {background-color: #3e8e41}
    .buttonSend:active {
      background-color: #3e8e41;
      box-shadow: 0 1px #666;
      transform: translateY(4px);
    }
    textarea { font-size: 24px; }
  </style>
</head>
<body>


<div>
  <h1>LEDPiKSEL.COM P10 Panel Kontrol Ekranı</h1>
  <h2><p id="Fiyat_1_H">Fiyat_1 :</p></h2>
  <textarea id="Fiyat1_text" name="Fiyat_1_text" rows="1" cols="5"></textarea><br>
  <button type="1" class="buttonSend" onclick="sendData('Fiyat1','q')">Fiyat 1 Güncelle</button>
</div>

<div>
  <h2><p id="Fiyat_2_H">Fiyat_2 :</p></h2>
  <textarea id="Fiyat2_text" name="Fiyat_2_text" rows="1" cols="5"></textarea><br>
  <button type="2" class="buttonSend" onclick="sendData('Fiyat2','t')">Fiyat_2 Güncelle</button>
</div>

<div>
  <h2><p id="Fiyat_3_H">Fiyat_3 :</p></h2>
  <textarea id="Fiyat3_text" name="Fiyat_3_text" rows="1" cols="5"></textarea><br>
  <button type="3" class="buttonSend" onclick="sendData('Fiyat3','e')">Fiyat_3 Güncelle</button>
</div>

<div>
  <h2><p id="Fiyat_4_H">Fiyat_4 :</p></h2>
  <textarea id="Fiyat4_text" name="Fiyat_4_text" rows="1" cols="5"></textarea><br>
  <button type="3" class="buttonSend" onclick="sendData('Fiyat4','r')">Fiyat_4 Güncelle</button>
</div>


<script>
  function sendData(i, q) {
    var Text = document.getElementById(i+"_text").value;
    var xhttp = new XMLHttpRequest();
    xhttp.open("GET", "setTex"+q+"?"+i+"="+Text, true);
    xhttp.send();
    window.alert(i+" fiyatı güncellendi : " + document.getElementById(i+"_text").value);
  }

</script>


</body>

</html>

)=====";

