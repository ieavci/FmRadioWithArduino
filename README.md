tr- TEA5767 radyo modülü kullanarak kendi radyomuzu yapıyoruz. <br>
en- We make our own radio using the TEA5767 radio module.

<hr>
<h2>Electronic circuit parts</h2>
<ul>
  <li>Arduino UNO</li>
  <li>TEA5767 radio module</li>
  <li>Breadbord</li>
  <li>Jumper</li>
</ul>

<h2>Code</h2>
```javascript
function helloWorld() {
    console.log("Merhaba, Dünya!");
}
helloWorld();


Bu şekilde kod bloğunu üç ters tırnak içine alarak ve dil belirttiğin kısımda (`javascript` gibi) ilgili programlama dilini belirtmen gerekiyor. Bu şekilde kullanıcılar, kodu seçip kopyalayabilir.

Bir alternatif olarak, bazı JavaScript kütüphaneleri veya eklentiler, kod bloklarına kopyalama butonu eklemek için kullanılabilir. Örneğin, Clipboard.js gibi bir kütüphane kullanarak kopyalama işlevselliği ekleyebilirsin. Bu kütüphane, kullanıcıların bir düğmeye tıklayarak kodu panolarına kopyalamalarını sağlar.

Örnek bir kopyalama düğmesi eklemek için:

```html
<!-- Örnek bir HTML kodu -->
<script src="https://cdnjs.cloudflare.com/ajax/libs/clipboard.js/2.0.8/clipboard.min.js"></script>
<!-- Kopyalama düğmesi -->
<button class="btn" data-clipboard-target="#kod">Kodu Kopyala</button>
<!-- Kod bloğu -->
<pre><code id="kod" class="javascript">
function helloWorld() {
    console.log("Merhaba, Dünya!");
}
helloWorld();
</code></pre>

