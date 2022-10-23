Name: %{getenv:VER_PROJECT_NAME}
Version: %{getenv:VER_PROJECT_VERSION}
Release: %{getenv:BUILD_NUMBER}
Summary: NextLabs Data Access Enforcer for Linux.
Group: Server
License: proprietary software
URL:https://www.nextlabs.com
BuildRoot:  %_topdir/BUILDROOT
%description
NextLabs Data Access Enforcer for Linux.

%install
%define project_folder %{getenv:WORKSPACE}
%define install_top_folder %{project_folder}/install/rpm/buildroot
%define dae_for_linux_folder  %{install_top_folder}/usr/nextlabs/daeforlinux
%define target_so_path %{project_folder}/install/rpm/Common

if [ -d %{buildroot} ];then
    rm -rf %{buildroot}/*
else
    mkdir %{buildroot}
fi

#remove content under install top folder
rm -rf %{install_top_folder}/*

#create dae_for_linux_folder
if [ -d %{dae_for_linux_folder} ];then
    rm -rf %{dae_for_linux_folder}/*
else
    mkdir -p %{dae_for_linux_folder}
fi

#copy common folder and header files
cp -rf %{target_so_path} %{dae_for_linux_folder}/
cp %{project_folder}/sqlenforcer/include/emdb_bigquery_sdk.h  %{dae_for_linux_folder}/Common/
cp %{project_folder}/sqlenforcer/include/emdb_sdk.h           %{dae_for_linux_folder}/Common/

#copy config folder
mkdir -p %{dae_for_linux_folder}/config/
cp -rf %{project_folder}/config/config_linux.ini  %{dae_for_linux_folder}/config/config.ini

#copy jdbc driver
mkdir -p %{dae_for_linux_folder}/JDBC/
cp -rf %{project_folder}/jdbc/jdbc_hana/bin/*.jar    %{dae_for_linux_folder}/JDBC/
cp -rf %{project_folder}/jdbc/jdbc_mssql/bin/*.jar   %{dae_for_linux_folder}/JDBC/
cp -rf %{project_folder}/jdbc/jdbc_nxl/bin/*.jar     %{dae_for_linux_folder}/JDBC/
cp -rf %{project_folder}/jdbc/jdbc_oracle/bin/*.jar  %{dae_for_linux_folder}/JDBC/
cp -rf %{project_folder}/jdbc_emdb_sdk/bin/*.jar     %{dae_for_linux_folder}/JDBC/

#move odbc driver
mkdir -p %{dae_for_linux_folder}/ODBC/
mv %{dae_for_linux_folder}/Common/bin64/libodbc_nxl.so %{dae_for_linux_folder}/ODBC/

#copy the whole directory to rpmbuild folder
cp -pfr %{install_top_folder}/*   %{buildroot}/

%files
/usr/*

%post
%define emdb_conf  /etc/ld.so.conf.d/nextlabs-emdb.conf
if [ $1 -eq 1 ] ; then
  if [ ! -f %{emdb_conf} ];then
    touch %{emdb_conf}
  else
    truncate -s 0 %{emdb_conf}
  fi
  echo "/usr/nextlabs/daeforlinux/Common/bin64" >> %{emdb_conf}
  echo "/usr/nextlabs/daeforlinux/ODBC" >> %{emdb_conf}
fi

%postun
if [ $1 -eq 0 ] ; then
  rm /etc/ld.so.conf.d/nextlabs-emdb.conf
  ldconfig
fi

%clean
%define RPM_PAGE_NAME_SRC %{name}-%{version}-%{release}.%{_target_cpu}.rpm
%define RPM_PAGE_NAME_DST %{name}-%{version}-%{release}.%{_target_cpu}.$(date +"%Y%m%d%H%M").rpm
%define result_rpm_package %{_topdir}/RPMS/x86_64/%{RPM_PAGE_NAME_SRC}
%define target_package_path %{project_folder}/install/rpm/package

if [ -d %{target_package_path} ];then
    rm -rf %{target_package_path}/*
else
    mkdir -p %{target_package_path}/
fi
cp -f %{result_rpm_package} %{project_folder}/install/rpm/package/%{RPM_PAGE_NAME_DST}

chmod 775 %{project_folder}/install/rpm/package/%{RPM_PAGE_NAME_DST}

rm -r %{buildroot}
