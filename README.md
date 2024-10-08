# Git Commands


```powershell
Sign in using auth token token~

Tabnine: Sign in using auth token token~
```
Авторизация


```powershell
git config --list

git config --global --replace-all user.email your-email

git config --global --replace-all user.name your-name
```
Смена пользователя

```powershell
ssh-keygen -t rsa -b 4096 -C EMAIL

Generating public/private rsa key pair.
Enter file in which to save the key (C:\Users\N1o/.ssh/id_rsa):
Created directory 'C:\Users\N1o/.ssh'.

Enter passphrase (empty for no passphrase):
Enter same passphrase again:

Your identification has been saved in C:\Users\N1o/.ssh/id_rsa.
Your public key has been saved in C:\Users\N1o/.ssh/id_rsa.pub.

The key fingerprint is:
_ email
The key's randomart image is:
+---[RSA 4096]----+
|                O|
|           .   o.|
|          . o o o|
|           + B +.|
|        S = B B +|
|         + X O B |
|          = E B .|
|           B B.o.|
|          o.+.+=.|
+----[SHA256]-----+
```
Генерация ssh

```powershell
git status
```
Проверьте статус изменений

```powershell
git init
```
Инициализируйте репозиторий

```powershell
git remote -v
git remote add origin https://github.com/ваш-аккаунт/ваш-репозиторий.git
```
Связали ваш локальный репозиторий с удаленным репозиторием GitHub


```powershell
git clone <URL_удаленного_репозитория>
```
Клонирует удаленный репозиторий на ваш локальный компьютер.


```powershell
git pull <удаленный_репозиторий> <ветка>
```
Забирает изменения с удаленного репозитория и автоматически сливает их с вашей локальной веткой.


```powershell
git log
```
Показывает историю коммитов с информацией о каждом коммите, такой как хеш, автор, дата и сообщение коммита.

----

```powershell
git add MainActivity.java
```
Добавьте файл

```powershell
git reset HEAD MainActivity.java
```
Снимает файлы из индекса, если вы случайно добавили их командой git add, но еще не сделали коммит

```powershell
git checkout -- MainActivity.java
```
Отменяет незафиксированные изменения в файлах, возвращая их к состоянию последнего коммита.


```powershell
git commit -m "Comments"
```
Зафиксируйте изменения


```powershell
git push origin
```
Загрузите изменения в удаленный репозиторий (не обязательно origin)


```powershell
git clean -fdx
```
удаляет всё, что незакоммители и возвращает последний комимт


```powershell
git checkout .
```
Выполнив эту команду, Git отменит все изменения в вашем рабочем каталоге и вернет его к состоянию последнего коммита. 


```powershell
git revert: Создает новый коммит, который отменяет изменения указанного коммита без удаления предыдущих коммитов.
```

Шаги:


```powershell
	Используйте git log, чтобы найти хеш целевого коммита (<target_commit_hash>).
	Выполните 
	git revert c3f4e5d7a8b9c0d1e2f3a4b5c6d7e8f9a0b1c2d3
	, чтобы создать новый коммит, отменяющий изменения.

git reset: Перемещает указатель HEAD и ветки на определенный коммит.
```

Варианты:


```powershell
	git reset --soft a1b2c3d4e5f6g7h8i9j0k1l2m3n4o5p6q7r8s9
	: Отменяет коммиты, сохраняя изменения в рабочем каталоге и индексе.
	git reset --mixed a1b2c3d4e5f6g7h8i9j0k1l2m3n4o5p6q7r8s9
	(по умолчанию): Отменяет коммиты и сбрасывает состояние индекса, сохраняя изменения в рабочем каталоге.
	git reset --hard a1b2c3d4e5f6g7h8i9j0k1l2m3n4o5p6q7r8s9
	: Отменяет коммиты и удаляет изменения в рабочем каталоге и индексе.
```

Шаги:


```powershell
	Используйте git log, чтобы найти хеш коммита, до которого нужно откатиться (<target_commit_hash>).
	Выполните 
	git reset --<option> <target_commit_hash>
	где <option> - это soft, mixed или hard, в зависимости от ваших потребностей.
```
