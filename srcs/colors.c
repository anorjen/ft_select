/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorjen <anorjen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 22:01:14 by anorjen           #+#    #+#             */
/*   Updated: 2020/11/20 12:51:49 by anorjen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static t_color	g_colors[] = {
	{"black", "\033[30m"},
	{"red", "\033[31m"},
	{"green", "\033[32m"},
	{"yellow", "\033[33m"},
	{"blue", "\033[34m"},
	{"purple", "\033[35m"},
	{"cyan", "\033[36m"},
	{"white", "\033[37m"},
	{"normal", "\033[0m"},
	{"inverse", "\033[7m"},
	{"underline", "\033[4m"},
	{"bold_green", "\033[1;32m"},
	{"bold_purple", "\033[1;35m"},
	{"bold_cyan", "\033[1;36m"},
	{"dark_white", "\033[2;37m"},
	{NULL, NULL}
};

static t_color	g_type_colors[] = {
	{"c", "blue"},
	{"h", "cyan"},
	{"o", "yellow"},
	{"7z", "bold_green"},
	{"ace", "bold_green"},
	{"alz", "bold_green"},
	{"arc", "bold_green"},
	{"arj", "bold_green"},
	{"bz", "bold_green"},
	{"bz2", "bold_green"},
	{"cab", "bold_green"},
	{"cpio", "bold_green"},
	{"deb", "bold_green"},
	{"dz", "bold_green"},
	{"ear", "bold_green"},
	{"gz", "bold_green"},
	{"jar", "bold_green"},
	{"lha", "bold_green"},
	{"lrz", "bold_green"},
	{"lz", "bold_green"},
	{"lz4", "bold_green"},
	{"lzh", "bold_green"},
	{"lzma", "bold_green"},
	{"lzo", "bold_green"},
	{"rar", "bold_green"},
	{"rpm", "bold_green"},
	{"rz", "bold_green"},
	{"sar", "bold_green"},
	{"t7z", "bold_green"},
	{"tar", "bold_green"},
	{"taz", "bold_green"},
	{"tbz", "bold_green"},
	{"tbz2", "bold_green"},
	{"tgz", "bold_green"},
	{"tlz", "bold_green"},
	{"txz", "bold_green"},
	{"tz", "bold_green"},
	{"tzo", "bold_green"},
	{"tzst", "bold_green"},
	{"war", "bold_green"},
	{"xz", "bold_green"},
	{"z", "bold_green"},
	{"Z", "bold_green"},
	{"zip", "bold_green"},
	{"zoo", "bold_green"},
	{"zst", "bold_green"},
	{"aac", "green"},
	{"au", "green"},
	{"flac", "green"},
	{"m4a", "green"},
	{"mid", "green"},
	{"midi", "green"},
	{"mka", "green"},
	{"mp3", "green"},
	{"mpa", "green"},
	{"mpeg", "green"},
	{"mpg", "green"},
	{"ogg", "green"},
	{"opus", "green"},
	{"ra", "green"},
	{"wav", "green"},
	{"doc", "green"},
	{"docx", "green"},
	{"dot", "green"},
	{"odg", "green"},
	{"odp", "green"},
	{"ods", "green"},
	{"odt", "green"},
	{"otg", "green"},
	{"otp", "green"},
	{"ots", "green"},
	{"ott", "green"},
	{"pdf", "green"},
	{"ppt", "green"},
	{"pptx", "green"},
	{"xls", "green"},
	{"xlsx", "green"},
	{"bmp", "green"},
	{"cgm", "green"},
	{"dl", "green"},
	{"dvi", "green"},
	{"emf", "green"},
	{"eps", "green"},
	{"gif", "green"},
	{"jpeg", "green"},
	{"jpg", "green"},
	{"JPG", "green"},
	{"mng", "green"},
	{"pbm", "green"},
	{"pcx", "green"},
	{"pgm", "green"},
	{"png", "green"},
	{"PNG", "green"},
	{"ppm", "green"},
	{"pps", "green"},
	{"ppsx", "green"},
	{"ps", "green"},
	{"svg", "green"},
	{"svgz", "green"},
	{"tga", "green"},
	{"tif", "green"},
	{"tiff", "green"},
	{"xbm", "green"},
	{"xcf", "green"},
	{"xpm", "green"},
	{"xwd", "green"},
	{"xwd", "green"},
	{"yuv", "green"},
	{"anx", "green"},
	{"asf", "green"},
	{"avi", "green"},
	{"axv", "green"},
	{"flc", "green"},
	{"fli", "green"},
	{"flv", "green"},
	{"gl", "green"},
	{"m2v", "green"},
	{"m4v", "green"},
	{"mkv", "green"},
	{"mov", "green"},
	{"MOV", "green"},
	{"mp4", "green"},
	{"mpeg", "green"},
	{"mpg", "green"},
	{"nuv", "green"},
	{"ogm", "green"},
	{"ogv", "green"},
	{"ogx", "green"},
	{"qt", "green"},
	{"rm", "green"},
	{"rmvb", "green"},
	{"swf", "green"},
	{"vob", "green"},
	{"webm", "green"},
	{"wmv", "green"},
	{"3des", "bold_purple"},
	{"aes", "bold_purple"},
	{"gpg", "bold_purple"},
	{"pgp", "bold_purple"},
	{"app", "bold_cyan"},
	{"bat", "bold_cyan"},
	{"btm", "bold_cyan"},
	{"cmd", "bold_cyan"},
	{"com", "bold_cyan"},
	{"exe", "bold_cyan"},
	{"reg", "bold_cyan"},
	{"bak", "dark_white"},
	{"BAK", "dark_white"},
	{"log", "dark_white"},
	{"log", "dark_white"},
	{"old", "dark_white"},
	{"OLD", "dark_white"},
	{"orig", "dark_white"},
	{"ORIG", "dark_white"},
	{"swo", "dark_white"},
	{"swp", "dark_white"},
	{NULL, NULL}
};

char			*get_color(char *color_name)
{
	int	i;

	if (color_name)
	{
		i = -1;
		while (g_colors[++i].name)
		{
			if (ft_strcmp(color_name, g_colors[i].name) == 0)
				return (g_colors[i].color);
		}
	}
	return (NULL);
}

char			*get_type_color_name(char *type)
{
	int	i;

	if (type)
	{
		i = -1;
		while (g_type_colors[++i].name)
		{
			if (ft_strcmp(type, g_type_colors[i].name) == 0)
				return (g_type_colors[i].color);
		}
	}
	return (NULL);
}

char			*get_type_color(char *type)
{
	char	*color_name;

	color_name = get_type_color_name(type);
	return (get_color(color_name));
}
