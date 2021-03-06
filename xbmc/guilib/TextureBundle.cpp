/*
 *      Copyright (C) 2005-2013 Team XBMC
 *      http://xbmc.org
 *
 *  This Program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2, or (at your option)
 *  any later version.
 *
 *  This Program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with XBMC; see the file COPYING.  If not, see
 *  <http://www.gnu.org/licenses/>.
 *
 */

#include "TextureBundle.h"

CTextureBundle::CTextureBundle()
  : m_useXBT{false}
{
}

bool CTextureBundle::HasFile(const std::string& Filename)
{
  if (m_useXBT)
  {
    return m_tbXBT.HasFile(Filename);
  }

  if (m_tbXBT.HasFile(Filename))
  {
    m_useXBT = true;
    return true;
  }

  return false;
}

void CTextureBundle::GetTexturesFromPath(const std::string &path, std::vector<std::string> &textures)
{
  if (m_useXBT)
  {
    m_tbXBT.GetTexturesFromPath(path, textures);
  }
}

bool CTextureBundle::LoadTexture(const std::string& Filename, CBaseTexture** ppTexture,
                                     int &width, int &height)
{
  if (m_useXBT)
  {
    return m_tbXBT.LoadTexture(Filename, ppTexture, width, height);
  }

  return false;
}

int CTextureBundle::LoadAnim(const std::string& Filename, CBaseTexture*** ppTextures,
                              int &width, int &height, int& nLoops, int** ppDelays)
{
  if (m_useXBT)
  {
    return m_tbXBT.LoadAnim(Filename, ppTextures, width, height, nLoops, ppDelays);
  }

  return 0;
}

void CTextureBundle::SetThemeBundle(bool themeBundle)
{
  m_tbXBT.SetThemeBundle(themeBundle);
}

std::string CTextureBundle::Normalize(const std::string &name)
{
  return CTextureBundleXBT::Normalize(name);
}
