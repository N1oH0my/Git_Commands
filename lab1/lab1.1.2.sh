sudo touch  /opt/name
sudo touch  /usr/lib/name.lib
sudo chmod og+x /usr/lib/name.lib
sudo touch  /etc/surname.conf
#sudo echo "/usr/lib/name.lib" >> /etc/surname.conf
#sudo echo "/opt/name" >> /etc/surname.conf

echo "/opt/name" |  sudo tee /etc/surname.conf

echo "/usr/lib/name.lib" |  sudo tee -a /etc/surname.conf






