Name: %{getenv:VER_PROJECT_NAME}-debuginfo
Version: %{getenv:VER_PROJECT_VERSION}
Release: %{getenv:BUILD_NUMBER}
Summary: NextLabs Data Access Enforcer for Linux debug info.
Group: Server
License: proprietary software
URL:https://www.nextlabs.com
BuildRoot:  %_topdir/BUILDROOT
%description
NextLabs Data Access Enforcer for Linux debug info.

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

#Move debug files
mkdir -p %{dae_for_linux_folder}/Common/bin64/
mv -f %{target_so_path}/bin64/*.debug %{dae_for_linux_folder}/Common/bin64/

#move odbc driver
mkdir -p %{dae_for_linux_folder}/ODBC/
mv %{dae_for_linux_folder}/Common/bin64/libodbc_nxl.so.debug %{dae_for_linux_folder}/ODBC/

#copy the whole directory to rpmbuild folder
cp -pfr %{install_top_folder}/*   %{buildroot}/

%files
/usr/*

%clean
%define RPM_PAGE_NAME_SRC %{name}-%{version}-%{release}.%{_target_cpu}.rpm
%define RPM_PAGE_NAME_DST %{name}-%{version}-%{release}.%{_target_cpu}.$(date +"%Y%m%d%H%M").rpm
%define result_rpm_package %{_topdir}/RPMS/x86_64/%{RPM_PAGE_NAME_SRC}
%define target_package_path %{project_folder}/install/rpm/package-debuginfo

if [ -d %{target_package_path} ];then
    rm -rf %{target_package_path}/*
else
    mkdir -p %{target_package_path}/
fi
cp -f %{result_rpm_package} %{target_package_path}/%{RPM_PAGE_NAME_DST}

chmod 775 %{target_package_path}/%{RPM_PAGE_NAME_DST}

rm -r %{buildroot}
