# Jak to działa?
Program odpalamy z konsoli za pomocą polecenia <br>
<pre>
  <code class="bash">
python main.py strategia parametr plik plik_z_rozwiazaniem plik_z_stat
  </code>
</pre>
lub
<pre>
  <code class="bash">
python3 main.py strategia parametr plik plik_z_rozwiazaniem plik_z_stat
  </code>
</pre>
Program zapisuje nam odpowiednie pliki w katalogu głównym i kończy program. <br>
Oczywiście najlepiej jest odpalić go przez załączone skrypty oraz programy, które są dostępne na WiKAMPie oraz zostały załączone w tym katalogu ;) <br>
Aby włączyć skrypt "uruchamiacz", musimy wpisać w konsoli <br>
<pre>
  <code class="bash">
./runprog.sh --STRATEGY --PARAM
  </code>
</pre>
gdzie <br>
- `STRATEGY` - strategia rozwiązywania układanki (bfs, dfs, astr)
- `PARAM` - odpowiedni parametr dla strategii (dla bfs i dfs może to być RDUL, LUDR, a dla astr jest to hamm lub manh)
### Dodatkowe programy
Załączone są również dodatkowe programy z WiKAMPa, takie jak
- `runval.sh` - skrypt sprawdzający poprawność algorytmów BFS, DFS, A*
- `puzzlegen.jar` - program generujący losowe plansze 15, które mają określoną ilość ruchów do znalezienia rozwiązania
- `puzzleval.jar` - program sprawdzający poprawność rozwiązania i przy okazji posiada wizualizację rozwiązania układanki przez program
## Edit
Program został mocno zmieniony ze względu na niepoprawne wyniki w A* oraz DFS, ale teraz wszystko powinno działać. <br>
Dodatkowo, dołączone są komentarze w kodzie, aby lepiej było zrozumieć co się dokładnie w nim dzieje ;)) <br>
**TODO** <br>
- [X] Odpalenie algorytmu DFS
- [X] Dokończenie sprawozdania
- [X] `push` do repo
- [X] Profit
