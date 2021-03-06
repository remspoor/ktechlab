/***************************************************************************
 *   Copyright (C) 2009 Julian Bäume <julian@svg4all.de>                   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 ***************************************************************************/

#ifndef DOCUMENTPLUGIN_H
#define DOCUMENTPLUGIN_H

#include "ktlinterfacesexport.h"

#include <interfaces/iplugin.h>
#include <QObject>
#include <QString>
#include <QVariantMap>

namespace KDevelop
{
class IDocument;
} // namespace KDevelop

namespace KTechLab
{

class Theme;
class ComponentItem;
class IComponentItemFactory;

/**
 * \short Base-class for Plugins handling documents
 * Sub-class this interface to support a new document-class for
 * KTechLab. KTechLab documents are composed of different components.
 * This interface unifies this and provides basic handling of these components.
 *
 * \author Julian Bäume
 */
class KTLINTERFACES_EXPORT IDocumentPlugin: public KDevelop::IPlugin
{
    Q_OBJECT
public:
    IDocumentPlugin( KComponentData data, QObject *parent = 0 );
    virtual ~IDocumentPlugin() {};

    /**
     * Each component factory can register itself at the document plugin, to make
     * it aware of it's presence. It will then determine which components the
     * factory has to offer and can handle them accordingly.
     *
     * \param factory - the component factory
     */
    virtual void registerComponentFactory( KTechLab::IComponentItemFactory * factory )=0;
    /**
     * When component plugins are unloaded, they can remove the components, they
     * provide from the document plugin, so these components won’t be available for
     * use any longer.
     *
     * \sa registerComponentFactory
     *
     * \param factory - the component factory
     */
    virtual void deregisterComponentFactory( KTechLab::IComponentItemFactory* factory )=0;

    /**
     * Get a factory that allows creating a certain KTechLab::ComponentItem from the given
     * \param name and \param theme.
     */
    virtual IComponentItemFactory* componentItemFactory( const QString& name, KTechLab::Theme* theme = 0 )=0;
};

} // namespace KTechLab

#endif

